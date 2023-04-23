#include <iostream>
#include <ffmpegcpp/ffmpegcpp.h>

using namespace std;
using namespace ffmpegcpp;

int main()
{
	// Prints duration of some videos, compare with output of ffprobe

    // 1. video
	try	{
		// Load a video from a container and read its info.
		const char* fileName = "samples/big_buck_bunny.mp4";

		Demuxer* demuxer = new Demuxer(fileName);
		ContainerInfo info = demuxer->GetInfo();

        auto microsec = info.durationInMicroSeconds;
        auto sec = info.durationInSeconds;

        std::cout << "samples/big_buck_bunny.mp4" << std::endl;
        std::cout << "Duration in microseconds: " << microsec << " -> " << (microsec == 60100000 ? "passed" : "failed") << std::endl;
        std::cout << "Duration in seconds: " << sec << " -> " << (sec == 60.1f ? "passed" : "failed") << std::endl;
	} catch (FFmpegException e)	{
		cerr << "Exception caught!" << endl;
		cerr << e.what() << endl;
		throw e;
	}

    // 2. video (remote video)
    try	{
        // Load a video from a container and read its info.
        const char* fileName = "https://download.samplelib.com/mp4/sample-5s.mp4";

        Demuxer* demuxer = new Demuxer(fileName);
        ContainerInfo info = demuxer->GetInfo();

        auto microsec = info.durationInMicroSeconds;
        auto sec = info.durationInSeconds;

        std::cout << "https://download.samplelib.com/mp4/sample-5s.mp4" << std::endl;
        std::cout << "Duration in microseconds: " << microsec << " -> " << (microsec == 5764000 ? "passed" : "failed") << std::endl;
        std::cout << "Duration in seconds: " << sec << " -> " << (sec == 5.764f ? "passed" : "failed") << std::endl;
    } catch (FFmpegException e)	{
        cerr << "Exception caught!" << endl;
        cerr << e.what() << endl;
        throw e;
    }

    // 3. video (remote video)
    try	{
        // Load a video from a container and read its info.
        const char* fileName = "https://s3.amazonaws.com/_bc_dml/example-content/sintel_dash/sintel_vod.mpd";

        Demuxer* demuxer = new Demuxer(fileName);
        ContainerInfo info = demuxer->GetInfo();

        auto microsec = info.durationInMicroSeconds;
        auto sec = info.durationInSeconds;

        std::cout << "https://s3.amazonaws.com/_bc_dml/example-content/sintel_dash/sintel_vod.mpd" << std::endl;
        std::cout << "Duration in microseconds: " << microsec << " -> " << (microsec == 888005000 ? "passed" : "failed") << std::endl;
        std::cout << "Duration in seconds: " << sec << " -> " << (sec == 888.005f ? "passed" : "failed") << std::endl;
    } catch (FFmpegException e)	{
        cerr << "Exception caught!" << endl;
        cerr << e.what() << endl;
        throw e;
    }
}
