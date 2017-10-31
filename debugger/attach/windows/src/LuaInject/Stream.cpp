﻿#include "Stream.h"
#include <cstdlib>
#include <cassert>
#include "endian.h"

ByteInputStream::ByteInputStream(char * buff, int size) : m_size(size), m_position(0)
{
	m_buff = (char*)malloc(size);
	memcpy(m_buff, buff, size);
}

ByteInputStream::~ByteInputStream()
{
	free(m_buff);
}

unsigned int ByteInputStream::ReadUInt32()
{
	int size = sizeof(unsigned int);
	assert(m_position + size <= m_size, "overflow");
	auto value = readInt32InBigEndian(m_buff + m_position);
	m_position = m_position + size;
	return value;
}

size_t ByteInputStream::ReadSize()
{
	int size = sizeof(size_t);
	assert(m_position + size <= m_size, "overflow");
	auto value = readInt64InBigEndian(m_buff + m_position);
	m_position = m_position + size;
	return value;
}

void ByteInputStream::ReadString(std::string & value)
{
	unsigned int size = ReadUInt32();
	assert(m_position + size <= m_size, "overflow");
	value.copy((char*)m_buff[m_position], size);
	m_position = m_position + size;
}

ByteOutputStream::ByteOutputStream() : m_position(0)
{
	m_size = 1024 * 1024;
	m_buff = (char*)malloc(m_size);
}

ByteOutputStream::~ByteOutputStream()
{
	free(m_buff);
}

void ByteOutputStream::Write(void * data, int size)
{
	assert(m_position + size <= m_size);
	memcpy(m_buff + m_position, data, size);
	m_position += size;
}

void ByteOutputStream::WriteUInt32(unsigned int value)
{
	int size = sizeof(unsigned int);
	assert(m_position + size <= m_size);
	//writeInt32InLittleEndian(m_buff, value);
	writeInt32InBigEndian(m_buff + m_position, value);
	m_position += size;
}

void ByteOutputStream::WriteSize(size_t value)
{
	int size = 8;
	assert(m_position + size <= m_size);
	//writeInt64InLittleEndian(m_buff, value);
	writeInt64InBigEndian(m_buff + m_position, value);
	m_position += size;
}

void ByteOutputStream::WriteString(const std::string& value)
{
	int len = value.length();
	WriteUInt32(len);
	if (len > 0)
	{
		Write((void*)value.c_str(), len);
	}
}
