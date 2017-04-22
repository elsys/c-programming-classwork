#include <stdio.h>

struct job_offer_t {
	float income;
	int is_remote;
	int work_hours;
	int meetings[7];
};

int accept_offer(struct job_offer_t);

int main() {
	struct job_offer_t job;

	scanf("%f%d%d", &job.income, &job.is_remote, &job.work_hours);

	for (int i = 0; i < 7; i++) {
		scanf("%d", &job.meetings[i]);
	}

	printf("%d", accept_offer(job));

	return 0;
}

int accept_offer(struct job_offer_t offer) {
	if (offer.income <  1024.64) { return 0; }
	
	int meetings_count = 0;

	for (int i = 0; i < 7; i++) {
		meetings_count += offer.meetings[i];
	}

	if (offer.is_remote && meetings_count < 4) { return 1; }
	if ((!offer.is_remote) && meetings_count < 6) { return 1; }

	return 0;		
}










