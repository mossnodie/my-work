#include "lib/_ui.h"
#include "lib/_str.h"
#include "src/datastructs/list.h"

void ui_test();

int main() {
//
//    //  系统日志
//    _log log;
//    _new_log(&log);
//
//    // ui界面构建
//    _ui ui;
//    _new_ui(&ui);
//
//    // 单元测试
//    ui_test();










    list l;
    int a = 4;
    _new_list(&l, sizeof(int), &a);
    printf("%d",*(int*)l.head->data);

    return 0;
}



void ui_test() {

    _ui _ui = _get_ui_instance();
    int display_width = 40;

    _ui_print_head(_ui, display_width);

    _ui_print_custom(_ui, FUN1_DESC, display_width);
    _ui_print_custom(_ui, FUN2_DESC, display_width);
    _ui_print_custom(_ui, FUN3_DESC, display_width);
    _ui_print_custom(_ui, FUN4_DESC, display_width);

}

