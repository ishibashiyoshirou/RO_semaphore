#include <kernel.h>
#include <itron.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"

#include "kernel_cfg.h"
#include "sample1.h"
#include <stdlib.h>

volatile INT count_a=10; /*空き駐車スペース*/
volatile INT count_b=0; /*入庫待ち台数*/

/* 入場 */
void task_p_in(VP_INT exinf)
{
	syslog(LOG_INFO, "Task_Park_In Start");

	while(1){
		slp_tsk();
		syslog(LOG_INFO,"Task_Park_In --> セマフォの獲得");
		wai_sem(SEM1);
		count_a--;
		count_b--;
		syslog(LOG_INFO,"Task_Park_In --> セマフォの獲得成功");
		syslog(LOG_INFO,"車が入場しました（待ち%d台　空き%d台）",count_b,count_a);
	}
	ext_tsk();
}

/* 出場 */
void task_p_out(VP_INT exinf)
{
	syslog(LOG_INFO, "Task_Park_Out Start");
	while(1){
		slp_tsk();
		syslog(LOG_INFO,"Task_Park_Out --> セマフォの返却");
		sig_sem(SEM1);
		count_a++;
		syslog(LOG_INFO,"車が出場しました（待ち%d台　空き%d台）",count_b,count_a);
	}
	ext_tsk();
}

/* 来車 */
void task_c_in(VP_INT exinf)
{
	syslog(LOG_INFO, "Task_Car_Out Start");
	while(1){
		dly_tsk(rand()%1000); /*待ち状態(0～999ms)*/
		count_b++;
		syslog(LOG_INFO,"車が来ました。");
		wup_tsk(TASK_P_IN);
	}
	ext_tsk();
}

/* 出車 */
void task_c_out(VP_INT exinf)
{
	syslog(LOG_INFO, "Task_Car_Out Start");
	while(1){
		dly_tsk(rand()%2000); /*待ち状態(0～1999ms)*/
		syslog(LOG_INFO,"車が出ます。");
		wup_tsk(TASK_P_OUT);
	}
	ext_tsk();
}

/*メインタスク*/
void main_task(VP_INT exinf)
{
	/*ログ情報出力の設定*/
	syslog_msk_log(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG));
	syslog(LOG_INFO, "Main-->実行開始");
	syslog(LOG_INFO, "Main-->タスクの起動");
	act_tsk(TASK_P_IN);
	act_tsk(TASK_P_OUT);
	act_tsk(TASK_C_IN);
	act_tsk(TASK_C_OUT);
	syslog(LOG_INFO,"Main-->自タスクの終了");
	ext_tsk();
}
