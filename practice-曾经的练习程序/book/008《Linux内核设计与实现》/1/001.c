/*
 * 调度器实体结构
 */
struct sched_entity{
	struct load_weight 		load;
	struct rb_node 			run_node;
	struct list_head 		group_node;
	unsigned int			on_rq;
	u64						exec_start;
	u64						sum_exec_runtime;
	u64						vruntime;
	u64						prev_sum_exec_runtime;
	u64						last_wakeup;
	u64						avg_overlap;
	u64						nr_migrations;
	u64						start_runtime;
	u64						avg_wakeup;
};
