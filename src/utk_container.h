#ifndef UBERTK_CONTAINER_H_
#define UBERTK_CONTAINER_H_

#include <list>
#include <utk_widget.h>

namespace utk {

class Container : public Widget {
private:
	mutable std::list<Widget*>::iterator cache_iter;
	mutable int cache_idx;

	std::list<Widget*>::iterator get_iter_at(int idx) const;

protected:
	std::list<Widget*> cont;
	int spacing, border;

	virtual void layout() = 0;

public:
	typedef std::list<Widget*>::iterator iterator;
	typedef std::list<Widget*>::const_iterator const_iterator;

	Container();
	virtual ~Container();

	virtual bool handle_event(Event *event);

	virtual void add_child(Widget *w);
	virtual bool remove_child(Widget *w);

	virtual void raise_child(Widget *w);
	virtual void sink_child(Widget *w);

	virtual void set_spacing(int sp);
	virtual int get_spacing() const;

	virtual void set_border(int b);
	virtual int get_border() const;

	virtual iterator begin();
	virtual const_iterator begin() const;
	virtual iterator end();
	virtual const_iterator end() const;

	virtual Widget *operator[](int idx);
	virtual const Widget *operator[](int idx) const;

	virtual size_t size() const;

	virtual int get_width() const;

	virtual void draw() const;	// just calls the draw() of each contained widget
};



class HBox : public Container {
protected:
	virtual void layout();
};

class VBox : public Container {
protected:
	virtual void layout();
};

class NullBox : public Container {
protected:
	virtual void layout();
};


}

#endif	// UBERTK_CONTAINER_H_
