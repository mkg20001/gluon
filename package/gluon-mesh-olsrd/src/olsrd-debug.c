/* SPDX-FileCopyrightText: 2021-2023 Maciej Krüger <maciej@xeredo.it> */
/* SPDX-License-Identifier: BSD-2-Clause */

#include <libolsrdhelper.h>
#include "respondd-real.h"
#include <stdio.h>
#include <json-c/json.h>
#include <assert.h>

void d(const char * fnc, json_object * res) {
	if (!res) {
		printf("%s: failed\n\n", fnc);
	} else {
		const char * str = json_object_to_json_string_ext(res, JSON_C_TO_STRING_PLAIN);
		printf("%s: %s\n\n", fnc, str);
		json_object_put(res);
	}
}

void d2(const char * fnc, json_object * res, int code) {
	if (code) {
		printf("%s: failed %i\n\n", fnc, code);
		assert(!res);
	} else {
		const char * str = json_object_to_json_string_ext(res, JSON_C_TO_STRING_PLAIN);
		printf("%s: %s\n\n", fnc, str);
		json_object_put(res);
	}
}

int main (int argc, char *argv[]) {
	json_object *resp;

	d("get_traffic", get_traffic());

	d("provider_neighbours", real_respondd_provider_neighbours());

	d("provider_nodeinfo", real_respondd_provider_nodeinfo());

	d("provider_statistics", real_respondd_provider_statistics());

	d2("olsr1_nodeinfo", resp, olsr1_get_nodeinfo("version", &resp));

	d2("olsr2_nodeinfo", resp, olsr2_get_nodeinfo("nhdpinfo jsonraw link", &resp));

	d("l3roamd_clients", socket_request_json("/var/run/l3roamd.sock", "get_clients"));

	d("make_safe", make_safe("n"));

	return 0;
}
