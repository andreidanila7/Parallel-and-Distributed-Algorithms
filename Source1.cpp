using namespace std;
mutex mtx;
queue<int> Q;
int p;
condition_variable CondProd;
condition_variable CondCons;

void sem up()
void sem down()

void Producer()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(3);

		mtx.lock();
		while (Q.size == 10)
			CondProd.wait();



		Q.push(1);
		cout << "The product was added in que" << endl;
		mtx.unlock();



		CondCons.notify_all();
	}
}

void Consumer()
{
	while (true)

	{
		mtx.lock();
		std::this_thread::sleep_for(std::chrono::seconds(1));

		if (Q.size() == 0)
		{
			cout << "The queue is empty, please wait" << endl;
			mtx.unlock();
		}
		else
		{
			Q.pop();
			cout << "The product is out of the que." << endl;
			mtx.unlock();
		}
		while (Q.size == 0)
			CondCons.wait();
		CondProd.notify_all();
	}

}

int main()
{
	thread Prod(Producer);
	thread Cons(Consumer);

	Prod.join();
	Cons.join();


	system("pause");
	return 0;
}