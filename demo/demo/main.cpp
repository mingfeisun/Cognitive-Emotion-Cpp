//--------------------------------------------------------------------------------
// This code shows how to use Cognitive Emotion API in C++
//--------------------------------------------------------------------------------
// Author: Mingfei (Alex)
// Date: 2017-May-16
//--------------------------------------------------------------------------------

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <curl/curl.h>

using namespace std;

/********* Set up url and keys ***********/

// url address, no need to change
const string urlAddr = "https://westus.api.cognitive.microsoft.com/emotion/v1.0/recognize";

// API key, change to your key
const string apiKey = "da7bb7645b634e24bf5cde607b2cb652"; // Mingfei's key for testing


/********* Store results returned *******/

typedef struct MemoryStruct
{
	char* memory;
	size_t size;
} MemoryStruct;


/********* Callback function ************/

size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	size_t realsize = size * nmemb;
	MemoryStruct *mem = (MemoryStruct *)userp;

	mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
	if (mem->memory == NULL) {
		/* out of memory! */
		printf("not enough memory (realloc returned NULL)\n");
		return 0;
	}

	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;

	return realsize;
}


/********* Format results from request **/

bool requestContentFormat(char* pMemData) {

	printf("Raw result: %s", pMemData);

	map<string, float> resultsMap;
	resultsMap["sadness"] = 0;
	resultsMap["neutral"] = 0;
	resultsMap["contempt"] = 0;
	resultsMap["disgust"] = 0;
	resultsMap["anger"] = 0;
	resultsMap["surprise"] = 0;
	resultsMap["fear"] = 0;
	resultsMap["happiness"] = 0;

	char* ppEmotions[] = { "anger", "contemp", "disgust", "fear",
		"happiness", "neutral", "sadness", "surprise" };

	for (size_t i = 0; i < 8; i++)
	{
		char* pPos = strstr(pMemData, ppEmotions[i]);
		if (pPos == NULL)
		{
			return false; // not found, erro
		}
		stringstream stringInput(pPos + strlen(ppEmotions[i]) + 2); // pointer shifts to right pos
		stringInput >> resultsMap[ppEmotions[i]];
	}

	for (const auto &p : resultsMap)
	{
		printf("%s: %f;\n", p.first.c_str(), p.second);
	}

	return true;
}


/********* Call curl request  ***********/
// vData is the raw image data
void curlRequest(vector<unsigned char> vData) {
	CURL* curl;
	CURLcode res;

	MemoryStruct chunk;

	static int index = 0;
	if (++index > 3 )
	{
		index = 0;
	}
	chunk.memory = (char*)malloc(1);
	chunk.size = 0;

	struct curl_slist *list = NULL;

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, urlAddr.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, vData.size());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, reinterpret_cast<char*>(vData.data()));

		list = curl_slist_append(list, "Content-Type: application/octet-stream"); 
		string temp = "Ocp-Apim-Subscription-Key: " + apiKey;

		list = curl_slist_append(list, temp.c_str());

		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

		res = curl_easy_perform(curl);

		/* Check for errors */
		if (res != CURLE_OK) {
			printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}
		else {
			// extract the results
			requestContentFormat(chunk.memory);
		}

		curl_easy_cleanup(curl);
		free(chunk.memory);
		curl_global_cleanup();
	}
}

void main(void) {
	vector<unsigned char> test; // the raw image data
	curlRequest(test);
	printf("done");
	getc(stdin);
}