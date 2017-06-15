//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_HAS_LABEL_HPP_INCLUDED
#define FCPPT_RECORD_HAS_LABEL_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/label_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/has_key.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Tests if a record has an \link fcppt::record::label\endlink.

\ingroup fcpptrecord
*/
template<
	typename Record,
	typename Label
>
struct has_label
:
boost::mpl::has_key<
	fcppt::record::label_set<
		Record
	>,
	Label
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
