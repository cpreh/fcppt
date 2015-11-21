//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_DETAIL_MAJOR_MINOR_AT_LEAST_H_INCLUDED
#define FCPPT_CONFIG_DETAIL_MAJOR_MINOR_AT_LEAST_H_INCLUDED


#define FCPPT_CONFIG_DETAIL_MAJOR_MINOR_AT_LEAST(\
	major_ref,\
	major,\
	minor_ref,\
	minor\
) \
(\
(major) > (major_ref) \
|| \
((major) == (major_ref) && (minor) >= (minor_ref))\
)


#endif
