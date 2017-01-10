
#ifndef _PEARCLDIVER_H_
#define _PEARCLDIVER_H_
#include "claccess/clcontext.h"
#include "PearlDiver.h"
//#include "Hash.h"

typedef struct {
	CLContext cl;
	PearlDiver pd;
	size_t num_groups;
	size_t loop_count;
} PearCLDiver;

int init_pearcl(PearCLDiver *pd);
bool pearcl_search(PearCLDiver *pdcl, trit_t *const trits, size_t length, size_t min_weight_magnitude);

#endif /* _PEARCLDIVER_H_ */
