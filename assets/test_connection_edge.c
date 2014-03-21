#include "or.h"
#include "connection_edge.h"
#include "tinytest.h"
#include "tinytest_macros.h"


void test_connection_ap_supports_optimistic_data()
{
	const entry_connection_t *conn = (entry_connection_t*)malloc(sizeof(entry_connection_t));
	
	conn->edge_.on_circuit = NULL;
	
	tt_assert(connection_ap_supports_optimistic_data(conn) == 0);
	//If the edge connection is not using any circuit, then it doesn't support optimistic data
	
	circuit_t *circ = (circuit_t*)malloc(sizeof(circuit_t));
	circ->state = CIRCUIT_STATE_BUILDING;
	circ->purpose = CIRCUIT_PURPOSE_C_GENERAL;
	
	conn->edge_.on_circuit = circ;
	
	tt_assert(connection_ap_supports_optimistic_data(conn) == 0);
	//If the circuit is open, but the state of the circuit is not open, then it the circuit cannot support optimistic data
	
	free(conn);
	
	end:
	;
}


