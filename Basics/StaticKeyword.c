#include <stdio.h>

/**
 * Static Keyword in C
 * 1. Static for Local Variables (inside a function):
 * Normally, a local variable (inside a function) is created on the stack each time the function runs, and destroyed when the function ends.
 * But if you declare it as static, then:
 * It is created only once (in Data Segment, not stack).
 * It retains its value between function calls.
 * Its lifetime = entire program execution.
 * Its scope = only inside that function.
 * Note: Without static, count would reset to 0 every time.
 *
 * @param argc
 * @param argv
 * @return
 */

void counter() {
    static int count = 0; /* Created only once */
    count++;
    printf("Count = %d\n", count);
}

int main(int argc, char *argv[]) {
    counter(); /* Count = 1 */
    counter(); /* Count = 2 */
    counter(); /* Count = 3 */


}
