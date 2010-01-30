//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_AUTO_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_AUTO_CONTEXT_HPP_INCLUDED

#include <fcppt/log/context_location.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/noncopyable.hpp>

namespace fcppt
{
namespace log
{
namespace detail
{

class auto_context {
	FCPPT_NONCOPYABLE(auto_context)
public:
	auto_context(
		context_location const &,
		object &
	);

	~auto_context();

	context_location const
	location() const;
private:
	context_location const location_;
};

}
}
}

#endif
