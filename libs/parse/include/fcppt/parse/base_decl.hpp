//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/base_fwd.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/tag.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Result,
	typename Ch,
	typename Skipper
>
class base
:
	private fcppt::parse::tag
{
	FCPPT_NONCOPYABLE(
		base
	);
protected:
	base();
public:
	virtual
	~base();

	typedef
	Result
	result_type;

	virtual
	fcppt::parse::result<
		Ch,
		result_type
	>
	parse(
		fcppt::reference<
			fcppt::parse::state<
				Ch
			>
		>,
		fcppt::parse::context<
			Skipper
		> const &
	) const = 0;
};

}
}

#endif
