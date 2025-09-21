/*
 * ApacheLog: Find Top IP Address(es) in O(n)
 *
 * Approach:
 * 1) Extract the IP (first token) from each log line.
 * 2) Insert/increment in a simple hash table (separate chaining).
 * 3) Scan the table once to find the max count.
 * 4) Print all IPs with count == max.
 *
 * This is a minimal, self-contained hash map for strings (ASCII).
 * For production, prefer a mature library; this is instructional.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry {
    char *key; // IP string
    int count; // frequency
    struct Entry *next; // separate chaining
} Entry;

typedef struct HashTable {
    Entry **buckets;
    size_t nbuckets;
    size_t size; // number of stored distinct keys
} HashTable;

/* djb2 string hash */
static unsigned long hash_str(const char *s) {
    unsigned long h = 5381;
    int c;
    while ((c = (unsigned char) *s++)) {
        h = ((h << 5) + h) ^ (unsigned long) c; // h*33 ^ c
    }
    return h;
}

static char *my_strdup(const char *s) {
    size_t n = strlen(s) + 1;
    char *p = (char *) malloc(n);
    if (!p) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    memcpy(p, s, n);
    return p;
}

static HashTable *ht_create(size_t nbuckets) {
    HashTable *ht = (HashTable *) malloc(sizeof(HashTable));
    if (!ht) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    ht->buckets = (Entry **) calloc(nbuckets, sizeof(Entry *));
    if (!ht->buckets) {
        perror("calloc");
        exit(EXIT_FAILURE);
    }
    ht->nbuckets = nbuckets;
    ht->size = 0;
    return ht;
}

static void ht_free(HashTable *ht) {
    if (!ht) return;
    for (size_t i = 0; i < ht->nbuckets; ++i) {
        Entry *e = ht->buckets[i];
        while (e) {
            Entry *n = e->next;
            free(e->key);
            free(e);
            e = n;
        }
    }
    free(ht->buckets);
    free(ht);
}

static Entry *ht_find(HashTable *ht, const char *key) {
    unsigned long h = hash_str(key) % ht->nbuckets;
    Entry *e = ht->buckets[h];
    while (e) {
        if (strcmp(e->key, key) == 0) return e;
        e = e->next;
    }
    return NULL;
}

static void ht_inc(HashTable *ht, const char *key) {
    unsigned long h = hash_str(key) % ht->nbuckets;
    Entry *e = ht->buckets[h];
    while (e) {
        if (strcmp(e->key, key) == 0) {
            e->count++;
            return;
        }
        e = e->next;
    }
    // not found: insert new at head
    Entry *ne = (Entry *) malloc(sizeof(Entry));
    if (!ne) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    ne->key = my_strdup(key);
    ne->count = 1;
    ne->next = ht->buckets[h];
    ht->buckets[h] = ne;
    ht->size++;
}

/* Extract first token (IP) from a log line into out buffer. Returns 1 on success, 0 on failure. */
static int extract_ip(const char *line, char *out, size_t out_cap) {
    if (!line || !*line) return 0;
    size_t i = 0;
    while (line[i] && line[i] != ' ' && i + 1 < out_cap) {
        out[i] = line[i];
        i++;
    }
    if (i == 0 || (line[i] != ' ' && line[i] != '\0')) {
        // either empty or overflowed out buffer
        return 0;
    }
    out[i] = '\0';
    return 1;
}

int main(void) {
    const char *logs[] = {
        "10.0.0.1 - frank [10/Dec/2000:12:34:56 -0500] \"GET /a.gif HTTP/1.0\" 200 234",
        "10.0.0.3 - john [10/Dec/2000:12:35:00 -0500] \"POST /b.gif HTTP/1.0\" 200 245",
        "10.0.0.1 - frank [10/Dec/2000:12:35:10 -0500] \"GET /c.gif HTTP/1.0\" 200 256",
        "10.0.0.1 - frank [10/Dec/2000:12:35:10 -0500] \"GET /c.gif HTTP/1.0\" 200 256",
        "10.0.0.3 - alice [10/Dec/2000:12:36:00 -0500] \"GET /d.gif HTTP/1.0\" 200 267",
        "10.0.0.3 - frank [10/Dec/2000:12:36:30 -0500] \"GET /e.gif HTTP/1.0\" 200 278"
    };
    const size_t nlogs = sizeof(logs) / sizeof(logs[0]);

    // Create hash table (power of two or prime-ish bucket count; 1024 is fine for the sample)
    HashTable *ht = ht_create(1024);

    // Build frequency map
    char ipbuf[64];
    for (size_t i = 0; i < nlogs; ++i) {
        if (extract_ip(logs[i], ipbuf, sizeof(ipbuf))) {
            ht_inc(ht, ipbuf);
        } else {
            fprintf(stderr, "Warning: could not parse IP from line %zu\n", i);
        }
    }

    // Find max count
    int maxCount = 0;
    for (size_t b = 0; b < ht->nbuckets; ++b) {
        for (Entry *e = ht->buckets[b]; e; e = e->next) {
            if (e->count > maxCount) maxCount = e->count;
        }
    }

    // Collect and print all IPs tying for maxCount
    printf("Top IPs and Max Count: [");
    int first = 1;
    for (size_t b = 0; b < ht->nbuckets; ++b) {
        for (Entry *e = ht->buckets[b]; e; e = e->next) {
            if (e->count == maxCount) {
                if (!first) printf(", ");
                // match your Java List<String> where you added ip then count
                printf("\"%s\", \"%d\"", e->key, e->count);
                first = 0;
            }
        }
    }
    printf("]\n");

    ht_free(ht);
    return 0;
}
