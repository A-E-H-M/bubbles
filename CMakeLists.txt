# Copyright (c) 2024 Alex Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0
# (See accompanying file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required ( VERSION 3.14 FATAL_ERROR )

project ( bubbles
		  LANGUAGES CXX
		  DESCRIPTION "A sample animation using SFML" )

# Add library targets
add_executable( bubbles src/bubbles_main.cpp )

# Update the path to link to SFML
#target_include_directories( bubbles PUBLIC SFML )
target_compile_features( bubbles PRIVATE cxx_std_20 )

#end of file
