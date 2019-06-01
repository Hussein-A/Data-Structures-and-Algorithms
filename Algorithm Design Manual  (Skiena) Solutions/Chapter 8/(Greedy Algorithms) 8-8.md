8-8. In the single-processor scheduling problem, we are given a set of n jobs J. Each job i has a processing time ti, and a deadline di. 
A feasible schedule is a permutation of the jobs such that when the jobs are performed in that order, every job is finished before its 
deadline. The greedy algorithm for single-processor scheduling selects the job with the earliest deadline first. Show that if a 
feasible schedule exists, then the schedule produced by this greedy algorithm is feasible.   
.   
***Solution***   
Suppose that a solution exists but that the greedy algorithm is infeasible. Since our algorithm is iterative there must be some point where we
went from being able to reach a feasbile solution to not. Let that point be where we chose job s_i because of all the programs that have
yet to be completed its deadline was the closest instead of job s_j which would have kept us on the proper path to feasibility. let s_p be the last proper
choice before this. 
Let us suppose we take s_j instead then whatever other jobs s_k, s_k+1,... are deemed to be on the feasibility path. Notice however that at some point since
this supposed solution is feasible the sequence of jobs s_k,s_k+1,... must end with s_i (then whatever other jobs need
to be completed) since its deadline is the closest. That is t_1+...+t_p   +   t_j+t_k+...+t_i < d_i. But addition is commutative so we also have:
t_1+...+t_p   +   t_i+t_k +...+t_j < d_i (the spacing identifies time already spent on tasks vs time to be spent). 
That is to say choosing s_i first as with the greedy algorithm could not have screwed anything up. Do note
however a slight technicality, this last switcharoo was permitted to still be feasible precisely because d_i was the closest (ie. smallest) deadline in time
for tasks that are yet to be completed. The reason why this is necessary is because other wise this logic would permit us to say since 
t_1+t_2+...+t_k < d_k where k is the last task, it follows that any ordering t_2+t_4+...+t_1 < d_k is also permitted but this could miss a deadline
for t_i. This example demonstrates this principle more clearly: with time weight {1,5} with deadlines {2, 6} respectively. 1+5 is feasible
yet that does not mean that 5 then 1 is feasible (it misses the deadline of 2 for the first task with time cost 1).
