//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_IMPL_NEXT_ARG_HPP_INCLUDED
#define FCPPT_OPTIONS_IMPL_NEXT_ARG_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/option_name_set.hpp>


namespace fcppt
{
namespace options
{
namespace impl
{

fcppt::optional::object<
	fcppt::args_vector::const_iterator
>
next_arg(
	fcppt::args_vector const &,
	fcppt::options::option_name_set const &
);

}
}
}

#endif
