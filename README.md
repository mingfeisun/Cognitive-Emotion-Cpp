# Descriptions
This repo was created by Mingfei (Alex) when he was using the cognitive emotion API provided by Microsoft. He found this API was really useful but it did not provide C++ SDK. So he created this repo to implement a C/C++ version of emotionAPI SDK. 

# Microsoft Emotion API: C++ & Sample
This repo contains the C/C++ & sample for the Microsoft Emotion API, an offering within [Microsoft Cognitive Services](https://www.microsoft.com/cognitive-services), formerly known as Project Oxford.
* [Learn about the Emotion API](https://www.microsoft.com/cognitive-services/en-us/emotion-api)
* [Read the documentation](https://www.microsoft.com/cognitive-services/en-us/emotion-api/documentation)
* [Find more SDKs & Samples](https://www.microsoft.com/cognitive-services/en-us/SDK-Sample?api=emotion)


## The Client Library
This client library is a thin C client wrapper for the Microsoft Emotion API.

## The Sample
This sample demonstrates how to use C++ to call the Emotion API service via http requests, which is relized by [curl library](https://curl.haxx.se/). 

### How to use
 1. Build curl library following the instructions in curl-7.53.1/README. (already build for win 64 in this repo)
 2. Open solution in demo/demo.sln by Visual Studio
 3. Change parameters in demo/demo/main.cpp: apiKey

### Run the sample
Open the solution in demo/demo.sln, build and run.

### More
Other example code can be found in [this repo](https://github.com/mingfeisun/poseTest/blob/master/proc/FaceParser.cpp).

## License
All Microsoft Cognitive Services SDKs and samples are licensed with the MIT License.

## Contact
This code was writen by Mingfei(Alex) with reference to curl examples. For any questions, please contact Mingfei(Alex) via mingfei.sun.hk@gmail.com.
