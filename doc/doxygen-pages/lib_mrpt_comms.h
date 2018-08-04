/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2018, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+ */

/** \defgroup mrpt_comms_grp [mrpt-comms]

Communication utilities: serial ports, networking (TCP, DNS,...), pub/sub nodelets.

<small> <a href="index.html#libs">Back to list of all libraries</a> | <a href="modules.html" >See all modules</a> </small>
<br>

# Library `mrpt-comms`
<small> [New in MRPT 2.0.0] </small>

This C++ library is part of MRPT and can be installed in Debian-based systems with:

        sudo apt install libmrpt-comms-dev

Find below some examples of use.

## Nodelets-like Pub/Sub mechanism

MRPT provides a Publisher/Subscriber (Pub/Sub) pattern implementation for
intra-process (multiple threads) zero-copy super fast communication.

Thread creation and handling is the responsibility of the user.

The main concepts are:
* A `topic`: the name of a shared variable. If you are familiar with ROS, you
already know what a topic is. Topics are identified by unique strings,
e.g. `odometry`, `scan`.
* Directory: The central hub that holds all references to existing topics.
Usually only one should exist per process, but there is no actual limitation.
* Subscriber: An object that binds to a given topic and allows a user-given
function to be called whenever new data is published to the topic.
* Publish: The operation of publishing a new data piece to a named topic.
It's important to note that the call is **blocking**: all subscribers are
executed from the thread invoking publish(). Users are encouraged to design
subscribers such that their execution time are minimized, delegating heavy
computation to other worker threads.

All these concepts are illustrated in the example below. Note that two
subscribers are created: one with a lambda and another with a regular function.

See: \ref comms_nodelets_example/NodeletsTest_impl.cpp
\snippet comms_nodelets_example/NodeletsTest_impl.cpp example-nodelets

## HTTP request methods

mrpt::comms::net::http_get() is an easy way to GET an HTTP resource from any C++ program.
You can also use mrpt::comms::net::http_request() to access APIs requiring the POST method.

See: \ref comms_http_client/test.cpp
\snippet comms_http_client/test.cpp example-http-get


*/
