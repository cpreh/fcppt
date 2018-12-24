//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_CONTEXT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_CONTEXT_DECL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/context_fwd.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Skipper
>
class context
{
public:
	typedef
	fcppt::reference<
		Skipper const
	>
	skipper_ref;

	explicit
	context(
		skipper_ref
	);

	skipper_ref
	skipper() const;
private:
	skipper_ref skipper_;
};

}
}

#endif
