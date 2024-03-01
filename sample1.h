
/*各タスクの優先度の定義*/

#define MAIN_PRIORITY	5	/* メインタスクの優先度 */
					/* HIGH_PRIORITYより高くすること */

#define HIGH_PRIORITY	9	/* 並列に実行されるタスクの優先度 */
#define MID_PRIORITY		10
#define LOW_PRIORITY		11

/*ターゲットに依存する可能性のある定数の定義*/

#ifndef TASK_PORTID
#define	TASK_PORTID		1	/* 文字入力するシリアルポートID */
#endif /* TASK_PORTID */

#ifndef STACK_SIZE
#define	STACK_SIZE		4096		/* タスクのスタックサイズ */
#endif /* STACK_SIZE */

/*  関数のプロトタイプ宣言 */
#ifndef TOPPERS_MACRO_ONLY

extern void	task_p_in(VP_INT exinf);
extern void	task_p_out(VP_INT exinf);
extern void	task_c_in(VP_INT exinf);
extern void	task_c_out(VP_INT exinf);
extern void	main_task(VP_INT exinf);

#endif /* TOPPERS_MACRO_ONLY */
