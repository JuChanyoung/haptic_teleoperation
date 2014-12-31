#include "haptic_teleoperation/VirtualForcePrf.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "prf");
    ros::NodeHandle n;
    ros::NodeHandle n_priv("~");
    double freq;
    n_priv.param<double>("frequency", freq, 50.0);
    ros::Rate loop_rate(freq);

    //    double dmin= 1.2 ;
    //    double amax= 1.0 ;
    //    double rpz = 0.4 ;
    //    double  tahead = 2 ;

    double rpz[4] = {0.2, 0.4, 0.6, 0.8} ;
    double amax= 1.0 ;
    double  tahead = 2 ;




    VirtualForcePrf prf_obj(n);

    for ( int i = 0 ; i < 4 ; i++ )
    {
        double dmin= 3.0 * rpz[i] ;
        prf_obj.setParameters(dmin,amax,rpz[i],tahead) ;
        std::string name = prf_obj.testName(dmin,amax,rpz[i],tahead, i) ;
        prf_obj.runTest(name );
    }
    while(ros::ok())
    {
        std::cout << "loop" << std::endl;
        ros::spin();
        loop_rate.sleep();
    }

    return 0;
}
