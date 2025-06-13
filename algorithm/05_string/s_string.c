#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *Naive substring search ,Returns index of first or -1
 */
int find_match(char* str, char* p)
{
	for (int i = 0; i <= strlen(str) - strlen(p); i++) {
		bool match = true;
		for (int j = 0; j < strlen(p); j++) {
			//			printf("str[%d]=%c,p[%d]=%c\n", i, str[i], j, p[j]);
			if (str[i + j] != p[j]) {
				match = false;
			}
		}
		if (match) {
			return i;
		}
	}
	return -1;
}

void build_next_arr(char* str, int* next_arr)
{
	for (int i = strlen(str); i > 0; i--) {
		int start = 0;
		int end = i / 2;
		while (start < i / 2) {
			printf("str[%d]=%c,str[%d]=%c\n",start,str[start],end,str[end]);
			if (str[start] == str[end]) {
				start++;
				end++;
			} else {
				break;
			}
		}
		next_arr[i] = start;
		printf("next_arr->%d=%d\n", i, start);
	}
}

/**
 * Kmp substring search
*/
int find_match_kmp(char* str, char* p)
{
	int* next_arr = malloc(sizeof(int) * strlen(p));
	build_next_arr(p, next_arr);
	int offset = 0;
	for (int i = 0; i <= strlen(str) - strlen(p);) {
		bool match = true;
		for (int j = offset; i < strlen(p); j++) {
			if (str[i + j] != p[j]) {
				match = false;
				offset = next_arr[j - 1];
				i += offset;
			}
		}
		if (match) {
			return i;
		} else {
			offset = 0;
			i++;
		}
	}
	free(next_arr);
	return -1;
}
void main()
{
	char* str = "abcdeabc";
	char* pattern = "eabc";
	int index1 = find_match(str, pattern);
	printf("find_match str=%s,p=%s,result=%d\n", str, pattern, index1);
	char* pattern2 = "cdc";
	int index2 = find_match_kmp(str, pattern2);
	printf("find_match str=%s,p=%s,result=%d\n", str, pattern2, index2);
}
