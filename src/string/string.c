long strlen(const char* string)
{
	long length = 0;
	while(string[0])
	{
		string++;
		length++;
	}
	return length;
}

