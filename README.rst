.. _multicore_hello_world:

Multicore Hello World application
#################################

.. contents::
   :local:
   :depth: 2

The sample demonstrates how to build the Hello World application for the multicore SoC.
The sample adds a remote image as a child image from the sample source files.

Requirements
************

The sample supports the following development kits:

.. table-from-sample-yaml::

Overview
********

The sample demonstrates how to build a multicore Hello World application with the :ref:`zephyr:sysbuild`.
When building with Zephyr Sysbuild, the build system adds child images based on the options selected in the project's additional configuration and build files.
This sample shows how to inform the build system about dedicated sources for additional images.
Depending on the development kit, different cores are involved:

* On the nRF5340 SoC, the sample utilizes the application core and the network core.
* On the nRF54H20 SoC, the sample utilizes the application core and the PPR core.

The sample comes with the following additional files:

* :file:`Kconfig.sysbuild` - This file is used to add Sysbuild configuration that is passed to all the images.
  ``SB_CONFIG`` is the prefix for sysbuild’s Kconfig options.
* :file:`sysbuild.cmake` - The CMake file adds additional images using the :c:macro:`ExternalZephyrProject_Add` macro.
  You can also add the dependencies for the images if required.

Both the application and remote cores use the same :file:`main.c` that prints the name of the DK on which the application is programmed.

Building and running
********************

.. |sample path| replace:: :file:`samples/multicore/hello_world`
.. |build command| replace:: west build -b nrf54h20dk_nrf54h20_cpuapp\@soc1

.. include:: /includes/build_and_run_sb.txt
.. include:: /includes/build_and_run_54h.txt

Testing
=======

After programming the sample to your development kit, complete the following steps to test it:

.. tabs::

   .. tab:: nRF54H20

      1. |connect_terminal|
      #. Reset the kit.
      #. Observe the console output for both cores:

         * For the application core, the output should be as follows:

            .. code-block:: console

               *** Booting Zephyr OS build v2.7.99-ncs1-2193-gd359a86abf14  ***
               Hello world from nrf54h20dk_nrf54h20_cpuapp

         * For the PPR core, the output should be as follows:

            .. code-block:: console

               *** Booting Zephyr OS build v2.7.99-ncs1-2193-gd359a86abf14  ***
               Hello world from nrf54h20dk_nrf54h20_cpuppr

   .. tab:: nRF5340

      1. |connect_terminal|
      #. Reset the kit.
      #. Observe the console output for both cores:

         * For the application core, the output should be as follows:

            .. code-block:: console

               *** Booting Zephyr OS build v2.7.99-ncs1-2193-gd359a86abf14  ***
               Hello world from nrf5340dk_nrf5340_cpuapp

         * For the network core, the output should be as follows:

            .. code-block:: console

               *** Booting Zephyr OS build v2.7.99-ncs1-2193-gd359a86abf14  ***
               Hello world from nrf5340dk_nrf5340_cpunet
