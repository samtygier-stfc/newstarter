
class ShapeSorter{
public:
		ShapeSorter();
		ShapeSorter(std::vector<Shape> shapes);
		void printType() const;
		void printSide(int sides) const;
		void printAreaDescending() const;
		void printPerimeterDescending() const;
		bool compareShapesPerimeter(Shape* shape1, Shape* shape2) const;
		bool compareShapesArea(Shape* shape1, Shape* shape2) const;
private:
		std::vector<Shape> m_shapes;
};