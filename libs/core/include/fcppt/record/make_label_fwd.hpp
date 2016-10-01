//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_MAKE_LABEL_FWD_HPP_INCLUDED
#define FCPPT_RECORD_MAKE_LABEL_FWD_HPP_INCLUDED

#include <fcppt/record/label_fwd.hpp>
#include <fcppt/record/detail/make_tag.hpp>
#include <fcppt/record/detail/tag_name.hpp>


/**
\brief Creates an \link fcppt::record::label\endlink.

\ingroup fcpptrecord

Creates an \link fcppt::record::label\endlink, passing it a unique,
implementation-defined tag type.

\param name The name of the label type.
*/
#define FCPPT_RECORD_MAKE_LABEL(\
	name\
)\
FCPPT_RECORD_DETAIL_MAKE_TAG(\
	name\
); \
\
typedef \
fcppt::record::label<\
	FCPPT_RECORD_DETAIL_TAG_NAME(\
		name\
	) \
> \
name

#endif
