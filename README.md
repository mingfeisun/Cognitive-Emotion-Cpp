# Descriptions
This repo was created by me when I was using the cognitive emotion API provided by Microsoft. I found this API was really useful but it did not provide C++ SDK. So I created this repo to implement a C/C++ version of emotionAPI SDK. 

# Microsoft Emotion API: C++ & Sample
This repo contains the C/C++ & sample for the Microsoft Emotion API, an offering within [Microsoft Cognitive Services](https://www.microsoft.com/cognitive-services), formerly known as Project Oxford.
* [Learn about the Emotion API](https://www.microsoft.com/cognitive-services/en-us/emotion-api)
* [Read the documentation](https://www.microsoft.com/cognitive-services/en-us/emotion-api/documentation)
* [Find more SDKs & Samples](https://www.microsoft.com/cognitive-services/en-us/SDK-Sample?api=emotion)


## The Client Library
This client library is a thin C client wrapper for the Microsoft Emotion API.

The easiest way to use this client library is to get microsoft.projectoxford.emotion package from [nuget](<http://nuget.org>). Please go to [Emotion API Package in nuget](https://www.nuget.org/packages/Microsoft.ProjectOxford.Emotion/) for more details.

## The Sample
This sample is a Windows WPF application to demonstrate the use of Microsoft Cognitive Services Emotion API. It demonstrates emotion API by specifying a URL or using a stream.

### Build the sample
 1. Starting in the folder where you clone the repository (this folder)
 2. In a git command line tool, type `git submodule init` (or do this through a UI)
 3. Pull in the shared Windows code by calling `git submodule update`
 4. Start Microsoft Visual Studio 2015 and select `File > Open > Project/Solution`.
 5. Go to `Sample-WPF Folder`.
 6. Double-click the Visual Studio 2015 Solution (.sln) file EmotionAPI-WPF-Samples.
 7. Press Ctrl+Shift+B, or select `Build > Build Solution`.

### Run the sample


## License
All Microsoft Cognitive Services SDKs and samples are licensed with the MIT License. For more details, see
[LICENSE](</LICENSE.md>).

Sample images are licensed separately, please refer to [LICENSE-IMAGE](</LICENSE-IMAGE.md>).

## Developer Code of Conduct
Developers using Cognitive Services, including this client library & sample, are expected to follow the “Developer Code of Conduct for Microsoft Cognitive Services”, found at [http://go.microsoft.com/fwlink/?LinkId=698895](http://go.microsoft.com/fwlink/?LinkId=698895).
