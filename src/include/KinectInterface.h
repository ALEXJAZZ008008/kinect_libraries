#ifndef KINECTINTERFACE_H
#define KINECTINTERFACE_H

#include <memory>

#include "src/include/KinectBackend.h"
#include "src/include/KinectInputOutput.h"
#include "src/include/KinectObject.h"

//!
//! \class KinectInterface
//! \brief
//! \details
//!
class KinectInterface
{
public:

    //! Constructor,
    explicit KinectInterface();

    //! Destructor,
    ~KinectInterface();

    //! Copy and move constructos and assignment opperators,
    KinectInterface(KinectInterface &);
    KinectInterface & operator = (KinectInterface &);
    KinectInterface(KinectInterface &&);
    KinectInterface & operator = (KinectInterface &&);

    inline KinectBackend & get_kinect_backend_ref()
    {
        return m_kinect_backend_ref;
    }

    inline int set_kinect_backend_ref(KinectBackend &kinect_backend_ref) = delete;

    inline shared_ptr<KinectInputOutput> & get_kinect_input_output_ptr()
    {
        return m_kinect_input_output_ptr;
    }

    inline int set_kinect_input_output_ptr(shared_ptr<KinectInputOutput> &kinect_input_output_ptr)
    {
        m_kinect_input_output_ptr = kinect_input_output_ptr;

        return 1;
    }

    inline shared_ptr<KinectObject> & get_kinect_object_ptr()
    {
        return m_kinect_object_ptr;
    }

    inline int set_kinectobject_ptr(shared_ptr<KinectObject> &kinect_object_ptr)
    {
        m_kinect_object_ptr = kinect_object_ptr;

        return 1;
    }

    //! Create connections
    int kinect_interface_main();

    //! Disconnect or destruct remotely
    int kinect_interface_kill(bool);

    int update();

private:

    KinectBackend &m_kinect_backend_ref;

    shared_ptr<KinectInputOutput> m_kinect_input_output_ptr;

    shared_ptr<KinectObject> m_kinect_object_ptr;

    //! Called by destructor
    //! and any other methods aimign to destruct the class
    int destructor(bool);
};

#endif // KINECTINTERFACE_H
