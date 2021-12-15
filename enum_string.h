/*
	this code is entirely
	copied from an article on Habre

	https://habr.com/ru/post/518842/
*/
#pragma once

#define DECLARE_ENUM(T, values...)                                      \
	enum class T { values, MAX };                                       \
	char enum_##T##_base[sizeof(#values)] = #values;                    \
	const char* T##_tokens[static_cast<__underlying_type(T)>(T::MAX)];  \
	const char* const* T##_tmp_ptr = tokenize_enum_string(              \
    	const_cast<char*>(enum_##T##_base), sizeof(#values), T##_tokens,\
    	static_cast<__underlying_type(T)>(T::MAX));

#define enum_to_string(T, value) \
	(T##_tokens[static_cast<__underlying_type(T)>(value)])

static const char* const* tokenize_enum_string(char* base,
                                               int length,
                                               const char* tokens[],
                                               int size)
{
	int count = 0;
	tokens[count++] = base;
	for (int i = 1; i < length; ++i)
	{
		if (base[i] == ',')
		{
			base[i] = '\0';

			if (count == size)
			{
				return tokens;
			}

			do {
				if (++i == length)
				{
					return tokens;
				}
			} while (' ' == base[i]);

			tokens[count++] = base + i;
		}
	}

	return tokens;
}

static bool string_equals(const char* a, const char* b)
{
	int i = 0;
	for (; a[i] && b[i]; ++i)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}

	return (a[i] == b[i]);
}

static int string_to_enum_int(const char* const tokens[], int max,
                              const char* value)
{
	for (int i = 0; i < max; ++i) {
		if (string_equals(tokens[i], value)) {
			return i;
		}
	}

	return max;
}
#define string_to_enum(T, value)     \
	static_cast<T>(string_to_enum_int( \
		T##_tokens, static_cast<__underlying_type(T)>(T::MAX), value))
