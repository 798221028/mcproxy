/*
 * This file is part of mcproxy.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 * written by Sebastian Woelke, in cooperation with:
 * INET group, Hamburg University of Applied Sciences,
 * Website: http://mcproxy.realmv6.org/
 */

#include "include/hamcast_logging.h"
#include "include/utils/if_prop.hpp"
#include "include/utils/mc_socket.hpp"
#include "include/utils/mroute_socket.hpp"
#include "include/utils/addr_storage.hpp"
#include "include/proxy/proxy.hpp"
#include "include/proxy/timing.hpp"
#include "include/proxy/check_if.hpp"
#include "include/utils/if_prop.hpp"


#include <iostream>
using namespace std;

void test_log();
void test_mctables();
void test_MC_TestTool();
void test_mcproxy(int arg_count, char* args[]);
void test_test();

int main(int arg_count, char* args[]) {
    hc_set_default_log_fun(HC_LOG_TRACE_LVL);

    //test_MC_Tables();
    //test_MC_TestTool();

   test_mcproxy(arg_count,args);


    //test_test();
    return 0;
}

void test_log(){
    hc_set_default_log_fun(HC_LOG_TRACE_LVL);
    HC_LOG_TRACE("");

    HC_LOG_DEBUG("HC_LOG_DEBUG");
    HC_LOG_INFO("HC_LOG_INFO");
    HC_LOG_WARN("HC_LOG_WARN");
    HC_LOG_ERROR("HC_LOG_ERROR");
    HC_LOG_FATAL("HC_LOG_FATAL");
}

void test_mcproxy(int arg_count, char* args[]){
    hc_set_default_log_fun(HC_LOG_ERROR_LVL);

    proxy p;
    if(p.init(arg_count, args)){
        cout << "mcproxy started" << endl;
        cout << p.get_state_table() << endl;
        p.start();
        p.stop();
    }else{
        cout << "mcproxy stopped! For more informations see log files." << endl;
    }
}

void test_test(){
    addr_storage::test_addr_storage();

}
