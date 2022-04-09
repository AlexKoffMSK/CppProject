#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

namespace OpenCV
{
    void OpenCVTest()
    {
        std::cout << __FILE__ << std::endl;
        std::cout << __LINE__ << std::endl;
        
        cv::String image_path = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\Pictures\\1.jpg";
        //cv::String image_path = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\Pictures\\Bitmap.bmp";
        //cv::String image_path = "C:\\Bitmap.bmp";
        cv::Mat image = cv::imread(image_path, cv::IMREAD_COLOR);

        //return;
        try
        {
            resize(image, image, { 500,500 }, 0, 0, cv::INTER_NEAREST); 
        } 
        catch (cv::Exception exc) 
        {
            std::cout << exc.what() << std::endl;
            std::cout << exc.code << std::endl;
            std::cout << exc.err << std::endl;
            std::cout << exc.file << std::endl;
            std::cout << exc.func << std::endl;
            std::cout << exc.line << std::endl;
            std::cout << exc.msg << std::endl;
        }

        imshow("Image", image);

        cv::waitKey(0);
    }

    void OpenCVTest2()
    {
        cv::Mat img(700, 700, CV_8UC3);
        cv::RNG& rng = cv::theRNG();

        vector<cv::Point> points;

        for (int i = 0; i < 300; i++)
        {
            cv::Point pt;
            pt.x = rng.uniform(img.cols / 4, img.cols * 3 / 4);
            pt.y = rng.uniform(img.rows / 4, img.rows * 3 / 4);
            points.push_back(pt);
        }

        for (;;)
        {
            vector<cv::Point> hull;
            convexHull(points, hull, true);

            img = cv::Scalar::all(0);
            
            for (int i = 0; i < points.size(); i++)
            { 
                circle(img, points[i], 3, cv::Scalar(0, 0, 255), cv::FILLED, cv::LINE_AA);
            }

            polylines(img, hull, true, cv::Scalar(0, 255, 0), 1, cv::LINE_AA);

            imshow("hull", img);

            char key = (char)cv::waitKey(1);
            if (key == 27 || key == 'q' || key == 'Q') // 'ESC'
            {
                break;
            }
            
            //std::cout << "!" << std::endl;
            //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
            //std::cout << "!!" << std::endl;

            for (cv::Point& pt : points)
            {
                pt.x += rng.uniform(-5, 6);
                pt.y += rng.uniform(-5, 6);
            }
        }
    }

    void Test3DrawPoly()
    {
        cv::Mat img(700, 700, CV_8UC3);
        img = cv::Scalar::all(0);
        vector<cv::Point> points;
        cv::RNG& rng = cv::theRNG();

            //points.push_back(cv::Point{ 200,200 });
            //points.push_back(cv::Point{ 200,500 });
            //points.push_back(cv::Point{ 500,500 });
            //points.push_back(cv::Point{ 500,200 });
        
        while (true)
        {
            points.clear();
            img = cv::Scalar::all(0);
            for (int i = 0; i < 10; ++i)
            {
                points.push_back(cv::Point(rng.uniform(0, img.cols), rng.uniform(0, img.rows)));
            }

            polylines(img, points, true, cv::Scalar(0, 255, 0), 2, cv::LINE_AA);

            imshow("points", img);
            char key = (char)cv::waitKey(0);
            if (key == 27 || key == 'q' || key == 'Q') // 'ESC'
            {
                break;
            }
            
        }
    }







}

/*
[ WARN:0@0.082] global C:\build\master_winpack-build-win64-vc15\opencv\modules\imgcodecs\src\loadsave.cpp (239) cv::findDecoder imread_(''): can't open/read file: check file path/integrity
*/