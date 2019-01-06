//
// Created by moss on 1/2/19.
//

#ifndef GAMES_SCORE_STATISTICS_SORT_H
#define GAMES_SCORE_STATISTICS_SORT_H


#include "../objects/project.h"
//#include "../objects/project.c"
#include "../objects/contact.h"
#include "../datastructs/list.h"
#include "../datastructs/stack.h"
#include "../views/_ui.h"
#include "../../lib/str.h"
#include "output_info.h"

extern void sort_project_by_score(long pid, list *projects, list *contacts,list *school) ;

extern void find_project(long pid,long sid, list *contacts);

extern void sort_woman_project_by_score(list *projects, list *contacts);

extern void sort_school_by_score(list *projects, list *contacts);

extern void test(list *projects, list *contacts,list *school);


#endif //GAMES_SCORE_STATISTICS_SORT_H
