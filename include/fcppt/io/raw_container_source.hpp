#ifndef FCPPT_IO_RAW_CONTAINER_SOURCE_HPP_INCLUDED
#define FCPPT_IO_RAW_CONTAINER_SOURCE_HPP_INCLUDED

#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/shared_ptr.hpp>
#include <boost/iostreams/concepts.hpp>
#include <boost/next_prior.hpp>
#include <algorithm>
#include <iterator>
#include <ios>
#include <streambuf>

namespace fcppt
{
namespace io
{
/// This is sort of a replacement for
/// boost::iostreams::array_source. The problem with array_source is
/// that it doesn't have ownership over the
/// range. raw_container_source has ownership.
template<typename Container>
class raw_container_source
{
public:
	typedef
	char
	char_type;

	struct category
	:
		boost::iostreams::input_seekable,
		boost::iostreams::device_tag
	{
	};

	typedef
	Container
	container;

	typedef
	fcppt::shared_ptr<container>
	container_ptr;

	typedef typename
	container::const_iterator
	const_iterator;

	template<typename Iterator>
	explicit
	raw_container_source(
		Iterator const begin,
		Iterator const end)
	:
		chars_(
			fcppt::make_shared_ptr<container>(
				begin,
				end)),
		pos_(
			chars_->begin())
	{
	}

	std::streamsize
	read(
		char *target,
		std::streamsize const n)
	{
		std::streamsize const result = 
			std::min(
				n, 
				std::distance(
					pos_,
					chars_->cend()));

		// EOF
		if (result == 0u) 
			return -1;

		const_iterator const new_pos = 
			boost::next(
				pos_,
				result);

		std::copy(
			pos_,
			new_pos,
			target);

		pos_ = new_pos;
		return result;
	}

	std::streampos 
	seek(
		boost::iostreams::stream_offset const off,
		std::ios_base::seekdir const way)
	{
		switch (way)
		{
			case std::ios_base::beg:
				pos_ = 
					boost::next(
						chars_->cbegin(),
						off);
				break;
			case std::ios_base::cur:
				pos_ = 
					boost::next(
						pos_,
						off);
				break;
			case std::ios_base::end:
				pos_ =
					boost::prior(
						chars_->cend(),
						off);
				break;
			default: break;
		}
		return 
			std::distance(
				chars_->cbegin(),
				pos_);
	}
private:
	container_ptr const chars_;
	const_iterator pos_;
};
}
}

#endif
