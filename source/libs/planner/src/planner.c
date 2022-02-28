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

#include "planner.h"

int32_t qCreateQueryPlan(SPlanContext* pCxt, SQueryPlan** pPlan) {

}

void qSetSubplanExecutionNode(SSubplan* subplan, uint64_t templateId, SDownstreamSource* pSource) {

}

int32_t qSubPlanToString(const SSubplan* subplan, char** str, int32_t* len) {

}

int32_t qStringToSubplan(const char* str, SSubplan** subplan) {

}

char* qQueryPlanToString(const SQueryPlan* pPlan) {

}

SQueryPlan* qStringToQueryPlan(const char* pStr) {

}

void qDestroyQueryPlan(SQueryPlan* pPlan) {

}
