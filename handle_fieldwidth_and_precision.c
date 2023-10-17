#include "main.h"
/**
 * handle_field_width-handle field width
 * @field_width: field width
 * @total_length: total length
 * @zero_padding: padding with 0 if empty
 * @l_align: left alignment (-)
 * @padding_char: padding characters
 * Return:total length
 */
int handle_field_width(int field_width, int total_length,
		int zero_padding, int l_align, char padding_char)
{
	int pad_len = field_width - total_length;

	if (pad_len > 0)
	{
		if (l_align)
		{
			while (pad_len-- > 0)
			{
				write(1, &padding_char, 1);
			}
		}
		else
		{
			if (zero_padding)
			{
				if (padding_char == ' ' && total_length > 0)
				{
					write(1, &padding_char, 1);
					total_length++;
					pad_len--;
				}
				while (pad_len-- > 0)
				{
					write(1, &padding_char, 1);
				}
			}
			else
			{
				while (pad_len-- > 0)
				{
					write(1, " ", 1);
				}
			}
		}
		return (field_width);
	}
	return (total_length);
}
/**
 * handle_precision-handle precision
 * @precision: precision
 * @num_str: pointer to the string variable
 * Return:length
 */
int handle_precision(int precision, char *num_str)
{
	int length = strlen(num_str);

	if (precision >= 0 && precision < length)
	{
		num_str[precision] = '\0';
		return (precision);
	}
	return (length);
}
