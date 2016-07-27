/*
 * rearrange程序的下列语句
 * 				if(columns[col] > len...)
 * 					break;
 * 当字符的列范围超出输入行的末尾时就停止复制。这条语句只有当列范围已递增顺序出现时才是正确的，
 * 但是事实并不一定如此。请修改这条语句，即使列范围不是按照顺序读取时也能正确完成任务
 */
/*
 * 当输出行已经满了的时候，我们仍然可以中断循环，但是在其他情况下循环必须继续。我们必须同时检查
 * 每个范围内已经复制了多少个字符，以防止一个NUL字节过早被复制到输出缓冲区。
 */

void rearrange(char *output, char const *input, 
		int const n_columns, int const columns[])
{
	int col;
	int output_col;
	int len;

	len = strlen(intput);
	output_col = 0;

	for( col = 0; col < n_columns; col += 2){
		int nchars = columns[col + 1] - columns[col] + 1;
		if( columns[col] >= len)
			continue;

		if( output_col == MAX_INPUT - 1 )
			break;

		if( output_col + nchars > MAX_INPUT - 1 )
			nchars = MAX_INPUT - output_col - 1;

		if( columns[col] + nchars - 1 >= len)
			nchars = len - columns[col];

		strncpy( ourput + output_col, input + columns[col], nchars);
		output_col += nchars;
	}

	output[output_col] = '\0';
}
