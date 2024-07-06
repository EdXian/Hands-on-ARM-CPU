/********************************************************************
Copyright 2010-2017 K.C. Wang, <kwang@eecs.wsu.edu>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/


int strlen(char *s)
{
  int i = 0;
  while(*s){
    i++; s++;
  }
  return i;
}

int strcmp(char *s1, char *s2)
{
  while((*s1 && *s2) && (*s1==*s2)){
      s1++; s2++;
  }
  if ((*s1==0) && (*s2==0))
    return 0;
  return(*s1 - *s2);

}
int bcopy(const void *src, void *dest, unsigned int n) {
	const char *s = (const char *)src;
	char *d = (char *)dest;
	if (s <= d)
		for (; n>0; --n)
			d[n-1] = s[n-1];
	else
		for (; n>0; --n)
			*d++ = *s++;
}

int atoi(char *s)
{
  int v = 0;
  while(*s){
    v = 10*v + (*s - '0');
    s++;
  }
  return v;
}


int bzero(void *dest, unsigned int n) {
	memset(dest, 0, n);
}


char *memcpy(void *dest, const void *src, unsigned int n) {
	bcopy(src, dest, n);
	return dest;
}


char *memset(void *dest, int c, unsigned int n) {
	char *d = (char *)dest;
	for (; n>0; --n)
		*d++ = (char)c;
	return dest;
}


int memcmp(const void *s1, const void *s2, unsigned int n) {
	const char *s3 = (const char *)s1;
	const char *s4 = (const char *)s2;
	for (; n>0; --n) {
		if (*s3 > *s4)
			return 1;
		else if (*s3 < *s4)
			return -1;
		++s3;
		++s4;
	}
	return 0;
}

char *kmemcpy(void *dest, const void *src, unsigned int n) {
	bcopy(src, dest, n);
	return dest;
}


char *kmemset(void *dest, int c, unsigned int n) {
	char *d = (char *)dest;
	for (; n>0; --n)
		*d++ = (char)c;
	return dest;
}


int kmemcmp(const void *s1, const void *s2, unsigned int n) {
	const char *s3 = (const char *)s1;
	const char *s4 = (const char *)s2;
	for (; n>0; --n) {
		if (*s3 > *s4)
			return 1;
		else if (*s3 < *s4)
			return -1;
		++s3;
		++s4;
	}
	return 0;
}


char *strcpy(char *dest, const char *src) {
	char *p = dest;
	while ( (*dest++ = *src++))
		;
	*dest = 0;
	return p;
}

int strcat(char *s1, char *s2)
{
  while(*s1)
    s1++;
  while(*s2)
    *s1++ = *s2++;
  *s1 = 0;
}

int strncpy(char *s1, char *s2, int n)
{
  char *p = s1;
  while(n && *s2){
    *s1++ = *s2++;
    n--;
  }
  *s1 = 0;
  return (int)p;
}

int strncmp(char *s1, char *s2, int n)
{
  if (n==0) return 0;
  do{
    if (*s1 != *s2++)
      return *s1-*(s2-1);
    if (*s1++ == 0)
      break;
  } while(--n != 0);
  return 0;
}

int kstrcmp(const char *s1, const char *s2)
{
  while ((*s1 && *s2) && (*s1==*s2)){
      s1++; s2++;
  }
  if (*s1==0 && *s2==0)
    return 0;
  return *s1-*s2;
}

char *kstrcpy(char *dest, const char *src) {
	char *p = dest;
	while ( (*dest++ = *src++))
		;
	*dest = 0;
	return p;
}


int kstrlen(const char *s) {
	unsigned int n = 0;
	while (*s++)
		++n;
	return n;
}

int kstrcat(char *s1, char *s2)
{
  while(*s1)
    s1++;
  while(*s2)
    *s1++ = *s2++;
  *s1 = 0;
}

int kstrncpy(char *s1, char *s2, int n)
{
  char *p = s1;
  while(n && *s2){
    *s1++ = *s2++;
    n--;
  }
  *s1 = 0;
  return (int)p;
}

int kstrncmp(char *s1, char *s2, int n)
{
  if (n==0) return 0;
  do{
    if (*s1 != *s2++)
      return *s1-*(s2-1);
    if (*s1++ == 0)
      break;
  } while(--n != 0);
  return 0;
}
