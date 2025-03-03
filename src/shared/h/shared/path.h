#ifndef HEADER_FFAC9DC4B9614355B83974D54518C75E
#define HEADER_FFAC9DC4B9614355B83974D54518C75E

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <functional>
#include <stdio.h>

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#if SYSTEM_WINDOWS
#define DEFAULT_SEPARATOR "\\"
#else
#define DEFAULT_SEPARATOR "/"
#endif

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

bool PathIsSeparatorChar(char c);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// <pre>
// /dir1/dir2/dir3/blahblah.ext
// |--- folder ---||-- name --|
//                         |  |
//                        /   |
//                       |name|
// </pre>
//
// (the name part includes the extension)

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

std::string PathWithoutExtension(const std::string &path);

std::string PathGetFolder(const std::string &path);

std::string PathWithoutTrailingSeparators(const std::string &path);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

std::string PathJoined(const std::string &a, const std::string &b);
std::string PathJoined(const std::string &a, const std::string &b, const std::string &c);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

/* Returns an empty string if there's no file name - e.g., "x/". */
std::string PathGetName(const std::string &path);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

/* Returns NULL if there's no extension - e.g., "a.x/fred" - or a
 * pointer to the '.' followed by the extension.
 */
std::string PathGetExtension(const std::string &path);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

std::string PathGetEXEFileName(void);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

/* Compare two paths. Will ignore case and separator type as
* appropriate. Return value as per strcmp. */
int PathCompare(const std::string &a, const std::string &b);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

/* Retrieve names of all files in the given folder. (This isn't
 * actually a glob, as you don't get to specify a mask.) */
bool PathGlob(const std::string &folder, std::function<void(const std::string &path, bool is_folder)> fun);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// The file details retrieved are for advisory purposes only.
bool PathIsFileOnDisk(const std::string &path, uint64_t *file_size, bool *can_write);
bool PathIsFolderOnDisk(const std::string &path);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

bool PathCreateFolder(const std::string &name);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#endif
