/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TDENGINE_PARSERUTIL_H
#define TDENGINE_PARSERUTIL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "os.h"
#include "query.h"
#include "tmsg.h"
#include "ttoken.h"

typedef struct SMsgBuf {
  int32_t len;
  char   *buf;
} SMsgBuf;

int32_t buildInvalidOperationMsg(SMsgBuf* pMsgBuf, const char* msg);
int32_t buildSyntaxErrMsg(SMsgBuf* pBuf, const char* additionalInfo,  const char* sourceStr);

int32_t parserValidateIdToken(SToken* pToken);

typedef struct SKvParam {
  SKVRowBuilder *builder;
  SSchema       *schema;
  char           buf[TSDB_MAX_TAGS_LEN];
} SKvParam;

int32_t KvRowAppend(const void *value, int32_t len, void *param);

STableMeta* tableMetaDup(const STableMeta* pTableMeta);
SSchema *getTableColumnSchema(const STableMeta *pTableMeta);
SSchema *getTableTagSchema(const STableMeta* pTableMeta);
int32_t  getNumOfColumns(const STableMeta* pTableMeta);
int32_t  getNumOfTags(const STableMeta* pTableMeta);
STableComInfo getTableInfo(const STableMeta* pTableMeta);

#ifdef __cplusplus
}
#endif

#endif  // TDENGINE_PARSERUTIL_H
