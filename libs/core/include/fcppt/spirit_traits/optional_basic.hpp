//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SPIRIT_TRAITS_OPTIONAL_BASIC_HPP_INCLUDED
#define FCPPT_SPIRIT_TRAITS_OPTIONAL_BASIC_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/spirit/home/support/attributes.hpp>
#include <fcppt/config/external_end.hpp>


namespace boost
{
namespace spirit
{
namespace traits
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type,
	typename Domain
>
struct not_is_optional<
	fcppt::optional::object<
		Type
	>,
	Domain
>
:
boost::mpl::false_
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
