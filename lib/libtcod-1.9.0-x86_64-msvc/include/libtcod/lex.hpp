/* libtcod
 * Copyright © 2008-2018 Jice and the libtcod contributers.
 * All rights reserved.
 *
 * libtcod 'The Doryen library' is a cross-platform C/C++ library for roguelike
 * developers.
 * Its source code is available from:
 * https://github.com/libtcod/libtcod
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * The name of copyright holder nor the names of its contributors may not
 *       be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * This is a libtcod internal module.
 * Use at your own risks...
 */
#ifndef _TCOD_LEX_HPP
#define _TCOD_LEX_HPP

#include "lex.h"

class TCODLIB_API TCODLex {
public :
	TCODLex();
	TCODLex( const char **symbols, const char **keywords, const char *simpleComment="//",
		const char *commentStart="/*", const char *commentStop="*/", const char *javadocCommentStart="/**",
		const char *stringDelim="\"", int flags=TCOD_LEX_FLAG_NESTING_COMMENT);
	~TCODLex();

	void setDataBuffer(char *dat);
	bool setDataFile(const char *filename);

	int parse(void);
	int parseUntil(int tokenType);
	int parseUntil(const char *tokenValue);

	bool expect(int tokenType);
	bool expect(int tokenType,const char *tokenValue);

	void savepoint(TCODLex *savept);
	void restore(TCODLex *savept);
	char *getLastJavadoc();

	int getFileLine() { return ((TCOD_lex_t *)data)->file_line; }
	int getTokenType() { return ((TCOD_lex_t *)data)->token_type; }
	int getTokenIntVal() { return ((TCOD_lex_t *)data)->token_int_val; }
	int getTokenIdx() { return ((TCOD_lex_t *)data)->token_idx; }
	float getTokenFloatVal() { return ((TCOD_lex_t *)data)->token_float_val; }
	char *getToken() { return ((TCOD_lex_t *)data)->tok; }
	char getStringLastDelimiter() { return ((TCOD_lex_t *)data)->lastStringDelim; }
	char *getPos() { return ((TCOD_lex_t *)data)->pos; }
	char *getBuf() { return ((TCOD_lex_t *)data)->buf; }
	char *getFilename() { return ((TCOD_lex_t *)data)->filename; }
	char *getLastJavadocComment() { return ((TCOD_lex_t *)data)->last_javadoc_comment; }
	static const char *getTokenName(int tokenType) { return TCOD_lex_get_token_name(tokenType); }
protected :
	void *data;
};

#endif
