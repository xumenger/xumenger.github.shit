static void update_curr(struct cfs_rq* cfs_rq){
	struct sched_entity* curr = cfs_rq->curr;
	u64 now = rq_of(cfs_rq)->clock;
	unsigned long delta_exec;

	if(unlikely(!curr))
		return;
	/*
	 * 获得从最后一次修改负载后当前任务所占用的运行总时间（在32为系统上这不会溢出）
	 */
	delta_exec = (unsigned long)(now-curr->exec_start);
	if(!delta_exec)
		return;
	__update_curr(cfs_rq, curr, delta_exec);
	curr->exec_start = now;

	if(entity_is_task(curr)){
		struct task_struct* curtask = task_of(curr);
		trace_sched-stat_runtime(curtask, delta_exec, curr->vruntime);
		cpuacct_charge(curtask, delta_exec);
		account_group_exec_runtime(curtask, delta_exec);
	}
}
