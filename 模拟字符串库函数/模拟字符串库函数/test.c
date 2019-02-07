
size_t MyStrlen(const char* src)//模拟实现strlen,注意返回类型为size_t,但是size_t如果相减会隐式转换为大于零的数
{
	assert(src);
	size_t count = 0;
	while (*src)
	{
		count++;
		src++;
	}
	return count;
}

char* MyStrcpy(char* dest, const char* src)//模拟实现strcpy函数
{
	assert(src);
	char* ptr = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ptr;
}

char* MyStrncpy(char* dest, const char* src,int count)//模拟实现strncpy函数
{
	assert(src);
	char* ptr = dest;
	while (count--)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ptr;
}

char* MyStrcat(char* dest, const char* src)//模拟实现strcat函数
{
	assert(src);
	char* ptr = dest;
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ptr;
}

char* Mystrncat(char* dest, const char* src, int count)//模拟实现strncat函数
{
	assert(dest);
	char* ptr = dest;
	while (*dest)
	{
		dest++;
	}
	while (count--)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ptr;	
}

char* MyStrstr(const char* dest, const char* src)//模拟实现strstr函数
{
	assert(src);

	const char* s1 = dest;
	const char* s2 = src;
	const char* ptr = dest;
	while (*ptr)
	{
		s1 = ptr;
		s2 = src;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)ptr;
		}
		ptr++;
	}
	return NULL;
}

char* MyStrchr(const char* dest, const char* src)
{
	assert(dest);
	while (*dest)
	{
		if (*dest == src)
		{
			return dest;
		}
		dest++;
	}
	return NULL;
}

void* MyMemcpy(void* dest, const void* src, size_t count)//不考虑内存重叠问题
{
	assert(dest);
	void* ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		(char*)dest = (char*)dest + 1;
		(char*)src = (char*)src + 1;
	}
	return ret;
}

void* MyMemmove(void* dest, const void* src, size_t count)//考虑内存重叠问题
{
	assert(dest);
	assert(src);
	void* ret = dest;
	if (dest <= src || (char*)dest > ((char*)src + count))
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			(char*)dest = (char*)dest + 1;
			(char*)src = (char*)src + 1;
		}
	}
	else
	{
		dest = (char*)dest + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dest = *(char*)src;
			(char*)dest = (char*)dest - 1;
			(char*)src = (char*)src - 1;
		}
	}

	return ret;
}
int MyStrcmp(const char* str1, const char* str2)//模拟实现strcmp 
{
	assert(str1);
	assert(str2);

	while (*str1 == *str2) 
	{
		if (*str1 == '\0') 
		{
			return 0;
		}
		++str1;
		++str2;
	}
	return *str1 - *str2;
}
