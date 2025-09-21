/*
 * Anagram String Checker (C version)
 *
 * Approach:
 * 1) Frequency-count approach (O(n) time, O(1) space for ASCII):
 *    - If lengths differ, not anagrams.
 *    - Convert both to lowercase (logical comparison) and count chars in str1, decrement using str2.
 *    - If any count goes negative or a char appears that wasn't in str1, not anagrams.
 *
 * Notes:
 * - This implementation assumes ASCII (256 possible char values). For Unicode, use a different strategy.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* Return length if s != NULL, else 0 for safety */
static size_t safe_strlen(const char *s) {
    return s ? strlen(s) : 0;
}

/* Case-insensitive frequency comparison using ASCII table */
bool anagram_hashmap_like(const char *str1, const char *str2) {
    if (!str1 || !str2) return false;

    size_t n1 = safe_strlen(str1);
    size_t n2 = safe_strlen(str2);
    if (n1 != n2) return false;

    int count[256] = {0};

    // Count frequencies from str1 (case-insensitive)
    for (size_t i = 0; i < n1; ++i) {
        unsigned char c = (unsigned char) tolower((unsigned char) str1[i]);
        count[c]++;
    }

    // Decrement with str2 (case-insensitive)
    for (size_t i = 0; i < n2; ++i) {
        unsigned char c = (unsigned char) tolower((unsigned char) str2[i]);
        if (count[c] == 0) {
            return false; // char not present enough times
        }
        count[c]--;
    }

    return true; // all counts balanced to zero
}

/* Same idea as isAnagram from Java: uses a 256-sized count array */
bool is_anagram(const char *str1, const char *str2) {
    if (!str1 || !str2) return false;

    size_t n1 = safe_strlen(str1);
    size_t n2 = safe_strlen(str2);
    if (n1 != n2) return false;

    int count[256] = {0};

    for (size_t i = 0; i < n1; ++i) {
        unsigned char c = (unsigned char) tolower((unsigned char) str1[i]);
        count[c]++;
    }
    for (size_t i = 0; i < n2; ++i) {
        unsigned char c = (unsigned char) tolower((unsigned char) str2[i]);
        if (count[c] == 0) return false;
        count[c]--;
    }
    return true;
}

int main(void) {
    printf("Are 'listen' and 'silent' anagrams? %s\n",
           anagram_hashmap_like("listen", "silent") ? "true" : "false");

    printf("Are 'evil' and 'vile' anagrams? %s\n",
           anagram_hashmap_like("evil", "vile") ? "true" : "false");

    printf("Are 'triangle' and 'integral' anagrams? %s\n",
           anagram_hashmap_like("triangle", "integral") ? "true" : "false");

    printf("Are 'hello' and 'world' anagrams? %s\n",
           anagram_hashmap_like("hello", "world") ? "true" : "false");

    printf("Are 'dusty' and 'study' anagrams? %s\n",
           anagram_hashmap_like("dusty", "study") ? "true" : "false");

    // Also show the second function behaves the same:
    printf("is_anagram('Listen','Silent') -> %s\n",
           is_anagram("Listen", "Silent") ? "true" : "false");

    return 0;
}
