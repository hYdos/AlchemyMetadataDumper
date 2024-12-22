#include "fileio.hpp"

#include "Addresses.h"

#include <string.h>
#include <stdarg.h>

#if TARGET_PS3
#include <cell/fs/cell_fs_file_api.h>
#elif TARGET_CAFE
//...
#else
#error "unsupported platform"
#endif

#define WRITE_BUFFER_SIZE 0x200

FileWriter::FileWriter(const char* filepath)
{
#if TARGET_PS3
	cellFsOpen(filepath, CELL_FS_O_CREAT|CELL_FS_O_WRONLY, &_handle, NULL, 0);
#elif TARGET_CAFE
	_stdHandle = fopen(filepath, "w");
	_handle = _stdHandle != 0;
#else
#error "unsupported platform"
#endif
	if (!_handle)
	{
		_igReportPrintf("failed to open file handle for path %s\n", filepath);
		return;
	}

#if TARGET_PS3
	cellFsTruncate(filepath, 0);
#endif
}

FileWriter::~FileWriter()
{
	if(_handle)
	{
#if TARGET_PS3
		cellFsClose(_handle);
#elif TARGET_CAFE
		fclose(_stdHandle);
#else
#error "unsupported platform"
#endif
	}
}

int FileWriter::WriteText(int len, const char* text)
{
#if TARGET_PS3
	uint64_t written = 0;
	cellFsWrite(_handle, text, len, &written);
#elif TARGET_CAFE
	uint64_t written = fwrite(text, sizeof(char), len, _stdHandle);
#else
#error "unsupported platform"
#endif

	if (written != len)
	{
		_igReportPrintf("pain and suffering, didn't write enough data...\n");
	}
	return len;
}

int FileWriter::WriteTextf(int n, const char* fmt, ...)
{
	va_list args;
	va_start(args, n);

	char text[WRITE_BUFFER_SIZE];
	int res = __stubs::__sprintf(text, fmt, args);

	va_end(args);

#if TARGET_PS3
	uint64_t written = 0;
	cellFsWrite(_handle, text, res, &written);
#elif TARGET_CAFE
	uint64_t written = fwrite(text, sizeof(char), res, _stdHandle);
#else
#error "unsupported platform"
#endif // TARGET_PS3

	if (written != res)
	{
		_igReportPrintf("pain and suffering, didn't write enough data...\n");
	}
	return res;
}