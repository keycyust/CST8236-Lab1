#include <SFML/Graphics.hpp>
#include "TransformNode.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(600, 600), "Sky Dancer Balloon");

	/*shapes*/
	sf::CircleShape circle(30);
	sf::RectangleShape neckRect(sf::Vector2f(40.0f, 20.0f));
	sf::RectangleShape bodyRect(sf::Vector2f(50, 20));
	sf::RectangleShape rightUpperArmRect(sf::Vector2f(50, 20));
	sf::RectangleShape rightLowerArmRect(sf::Vector2f(50, 20));
	sf::RectangleShape leftUpperArmRect(sf::Vector2f(50, 20));
	sf::RectangleShape leftLowerArmRect(sf::Vector2f(50, 20));


	bodyRect.setSize(sf::Vector2f(40, 200));
	leftUpperArmRect.setSize(sf::Vector2f(80, 20));
	rightUpperArmRect.setSize(sf::Vector2f(80, 20));
	leftLowerArmRect.setSize(sf::Vector2f(80, 20));
	rightLowerArmRect.setSize((sf::Vector2f(80, 20)));

	/*setColor*/
	circle.setFillColor(sf::Color::Cyan);
	neckRect.setFillColor(sf::Color::Yellow);
	leftUpperArmRect.setFillColor(sf::Color::Green);
	rightUpperArmRect.setFillColor(sf::Color::Green);
	leftLowerArmRect.setFillColor(sf::Color::Red);
	rightLowerArmRect.setFillColor(sf::Color::Red);


	/*set position & rotation*/
	sf::Vector2f neckPosition((circle.getLocalBounds().height /1.75f), (circle.getLocalBounds().width /1.5f));
	sf::Vector2f neckOrigin(60.0f, 0.0f);

	sf::Vector2f bodyPosition((neckRect.getLocalBounds().height / 1.75f), (neckRect.getLocalBounds().width / 4.5f));
	sf::Vector2f bodyOrigin(5.0f, -55.0f);

	sf::Vector2f leftUpperArmPosition((bodyRect.getLocalBounds().height / 1.75f), (bodyRect.getLocalBounds().width / 4.5f));
	sf::Vector2f leftUpperArmOrigin(5.0f, -60.0f);

	sf::Vector2f rightUpperArmPosition((bodyRect.getLocalBounds().height / 1.75f), (bodyRect.getLocalBounds().width / 4.5f));
	sf::Vector2f rightUpperArmOrigin(5.0f, 60.0f);

	sf::Vector2f leftLowerArmPosition((leftUpperArmRect.getLocalBounds().height / 1.75f), (leftUpperArmRect.getLocalBounds().width / 4.5f));
	sf::Vector2f leftLowerArmOrigin(5.0f, 60.0f);

	sf::Vector2f rightLowerArmPosition((leftUpperArmRect.getLocalBounds().height / 1.75f), (leftUpperArmRect.getLocalBounds().width / 4.5f));
	sf::Vector2f rightLowerArmOrigin(5.0f, 60.0f);

	/*setOrigin*/
	circle.setOrigin(20.0f, 20.0f);
	circle.setPosition(250, 100);

	neckRect.setOrigin(neckOrigin);
	neckRect.setPosition(0.0f, 20.0f);

	bodyRect.setOrigin(bodyOrigin);
	bodyRect.setPosition(0.0f, 0.0f);

	leftUpperArmRect.setOrigin(leftUpperArmOrigin);
	leftUpperArmRect.setPosition(-55.0f, -15.0f);

	rightUpperArmRect.setOrigin(rightUpperArmOrigin);
	rightUpperArmRect.setPosition(94.0f, 5.0f);

	leftLowerArmRect.setOrigin(leftLowerArmOrigin);
	leftLowerArmRect.setPosition(-37.0f, 30.0f);

	rightLowerArmRect.setOrigin(leftLowerArmOrigin);
	rightLowerArmRect.setPosition(15.0f, -95.0f);

	/*set rotations*/
	neckRect.setRotation(100);
	neckRect.rotate(170);
	
	bodyRect.setRotation(100);
	bodyRect.rotate(-10);
	
	leftUpperArmRect.setRotation(-60);
	leftUpperArmRect.rotate(80);
	
	rightUpperArmRect.setRotation(432);
	rightUpperArmRect.rotate(90);

	leftLowerArmRect.setRotation(-240);
	leftLowerArmRect.rotate(30);

	rightLowerArmRect.setRotation(-325);
	rightLowerArmRect.rotate(180);

	/*Transform here*/
	TransformNode head(&circle);
	TransformNode neck(&neckRect);
	TransformNode body(&bodyRect);
	TransformNode leftUpperArm(&leftUpperArmRect);
	TransformNode rightUpperArm(&rightUpperArmRect);
	TransformNode leftLowerArm(&leftLowerArmRect);
	TransformNode rightLowerArm(&rightLowerArmRect);

	neck.AddChild(&body);
	body.AddChild(&leftUpperArm);
	body.AddChild(&rightUpperArm);
	leftUpperArm.AddChild(&leftLowerArm);
	rightUpperArm.AddChild(&rightLowerArm);
	head.AddChild(&neck);

	//head.AddChild(&body);

	sf::Clock deltaTime;
	bool keyHeld = false;

	while (window.isOpen())
	{

		float elapsedTime = deltaTime.restart().asSeconds();
		sf::Transform transform = circle.getTransform();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				keyHeld = false;
			}
			else if (event.type == sf::Event::KeyReleased)
			{
				keyHeld = true;
			}
		}

		if (keyHeld)
		{
			float angle = 90.0f;
			neckRect.rotate(angle * elapsedTime);
			bodyRect.rotate(angle * elapsedTime);
			leftUpperArmRect.rotate(angle * elapsedTime);
			rightUpperArmRect.rotate(-1 * angle * elapsedTime);
			leftLowerArmRect.rotate(angle * elapsedTime);
			rightLowerArmRect.rotate(-1 * angle * elapsedTime);

		}
	window.clear();

	/*draw*/
	//window.draw(circle);
	head.Draw(&window);

	window.display();

	}
	return 0;
}