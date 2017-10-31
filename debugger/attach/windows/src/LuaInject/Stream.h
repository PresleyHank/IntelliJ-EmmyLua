﻿#pragma once
#include <string>

class ByteInputStream
{
	char* m_buff;
	int m_size;
	int m_position;
public:
	ByteInputStream(char* buff, int size);
	~ByteInputStream();
	/**
	* Reads a 32-bit unsigned integer from the channel. This operation blocks
	* until the data is available.
	*/
	unsigned int ReadUInt32();

	size_t ReadSize();

	/**
	* Reads a string from the channel. This operation blocks until the
	* data is available.
	*/
	void ReadString(std::string& value);
};

class ByteOutputStream
{
	char* m_buff;
	size_t m_size;
	int m_position;
public:
	ByteOutputStream();
	~ByteOutputStream();

	void Write(void* data, int size);

	void WriteUInt32(unsigned int value);

	void WriteSize(size_t value);

	void WriteString(const std::string& value);

	const char* GetBuf() const { return m_buff; }

	size_t GetSize() const { return m_size; }

	int GetPositon() { return m_position; }

	void Reset() { m_position = 0; }
};