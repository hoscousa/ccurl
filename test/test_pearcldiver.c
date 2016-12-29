#include "../src/lib/pearcldiver.h"
#include "../src/lib/ccurl.h"
#include "../src/lib/PearlDiver.h"
#include "../src/lib/util/converter.h"
#include "../src/lib/Curl.h"

#include "cunit_include.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#define SIZE_IN_BYTES  49
//static const char *tryte_nines = "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
static const char *real_transaction = "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999ZDWNRTMICEUJKUZIZGXKNUXGTFQTGNXHYHYYQYLWPPWKRWFVTIOBFGMVLKGCOGHF9LINGNLPHQBO9UHSE999999999999999999999999999999999999999999999999999999CAAUHVD99999999999999999999HRNCLJOVIU999QYHADTTFLUMTDSUAYKUUBWCWACGEPWZQUHQDWSGMFFKNHAIUUVQHPXOTHFFGLUUMYRMK999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
//static const char *real_trans_w_hash = "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999ZDWNRTMICEUJKUZIZGXKNUXGTFQTGNXHYHYYQYLWPPWKRWFVTIOBFGMVLKGCOGHF9LINGNLPHQBO9UHSE999999999999999999999999999999999999999999999999999999CAAUHVD99999999999999999999HRNCLJOVIU999QYHADTTFLUMTDSUAYKUUBWCWACGEPWZQUHQDWSGMFFKNHAIUUVQHPXOTHFFGLUUMYRMKPYHODCQSKTYJBNXYLMDXGTAIDMXNNXZPCJZD9PAXVITTAPLDDDAVZXHVY9QABYMTFGODIGFV9JZFW9999UNBHOV9VMEMRMBPJLEIJLUMXNFTSOMQ9JLNPAKOPIXALNXQHOMNRJPSRJOQYYWWXZJJX9FYOSKB999999XBKFGDZLRGMOMLDTQZOQ9DVUCNWCAXKOWCQDLLGMZAZKYYKIIQBT9X9RRMTMPPOAN9UJYKKBGNSWAZVHJ";

static int init_suite(void) {
	init_converter();
	return 0;
}
static int clean_suite(void) {
	return 0;
}
static void init_cl_test(void) {
}
static void teardown_cl_test(void) {
}

bool test_last_n_nines(char *hash, int length, int numNines) {
	int i;
	for( i = 1; i<= numNines; i++) {
		if(hash[length-i] != '9') return false;
	}
	return true;
}

static void test_search(void) {
	PearCLDiver pdcl;
	Curl curl;
	clock_t start,diff;
	int nonce_size = 15;
	char *digest, *trans;

	trit_t *mytrits, hash_trits[HASH_LENGTH];


	if(init_pearcl(&pdcl) != 0) {
		CU_FAIL("E: Could not initialize opencl\n");
		return;
	}
	init_curl(&curl);
	mytrits = trits_from_trytes(real_transaction, TRYTE_LENGTH);
	
	//puts(trytes_from_trits(mytrits+TRANSACTION_LENGTH-HASH_LENGTH, 0, HASH_LENGTH));

	start = clock();
	pearcl_search(&pdcl, mytrits, TRANSACTION_LENGTH, nonce_size);
	diff = clock() - start;

	//printf("I took this many seconds: %ld", diff / CLOCKS_PER_SEC);
	trans = trytes_from_trits(mytrits, 0, TRANSACTION_LENGTH);
	//hash = trytes_from_trits(mytrits + TRANSACTION_LENGTH - HASH_LENGTH, 0, HASH_LENGTH);
	

	absorb(&curl, mytrits, 0, TRANSACTION_LENGTH);
	squeeze(&curl, hash_trits, 0, HASH_LENGTH);

	digest = trytes_from_trits(hash_trits, 0, HASH_LENGTH);

	puts(trans);
	puts(digest);
	CU_ASSERT_FATAL(test_last_n_nines(digest, HASH_LENGTH/3, nonce_size/3));

	free(mytrits);
	free(digest);
}

static CU_TestInfo tests[] = {
	{"Test Search ", test_search},
	CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
	{ "CLContext Test Suite", init_suite, clean_suite, init_cl_test,teardown_cl_test, tests },
	CU_SUITE_INFO_NULL,
};

int main() {
	return run_tests(suites);
}
