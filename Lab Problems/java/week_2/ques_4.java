import java.io.*;
import java.lang.*;
import java.util.*;

class department{
	private String itemName;
	private int itemCode;
	private float price;
	private int qtylnStock;
	private int soldToday;

	//constructor
	public department(String itemName , int itemCode , float price , int qtylnStock , int soldToday){
		this.itemCode=itemCode;
		this.itemName=itemName;
		this.price=price;
		this.qtylnStock=qtylnStock;
		this.soldToday=soldToday;

	}
	//getter func
	public int getItemcode(){
		return itemCode;
	}

	public String getItemName(){
		return itemName;
	}

	public float getPrice(){
		return price;
	}
	public int getQtynStock(){
		return qtylnStock;
	}
	public int getSoldToday(){
		return soldToday;
	}
	//setter func
	public void setItemCode(int itemCode){
		this.itemCode=itemCode;
	}

	public void setItemName(String itemName){
		this.itemName= itemName;
	}

	public void setQtynStock(int qtylnStock){
		this.qtylnStock=qtylnStock;
	}
	public void setSoldToday(int soldToday){
		this.soldToday=soldToday;
	}

	public void setPrice(float price){
		this.price=price;
	}
}


public class ques_4{
	int menu(){
		System.out.println("************************menu********************************");
		System.out.println("	Add a new item");
		System.out.println("	Update the price of an item");
		System.out.println("	Update the stock");
		System.out.println("	Show the price list");
		System.out.println("	Sell an item");
		System.out.println("	Exit");
		System.out.println("************************************************************");
		Scanner sc =new Scanner(System.in);
		int x =sc.nextInt();
		return x;

	}

	public static void main(String args[]){
		Scanner sc =new Scanner(System.in);
		ques_4 menu =new ques_4();
		int total_items=0;
		department[] items =new department[100];
		int x =menu.menu();
		while(x!=6){
			if(x==1){
				int itemCode=sc.nextInt();
				String itemName=sc.next();
				float price=sc.nextFloat();
				int qtylnStock =sc.nextInt();
				int soldToday =sc.nextInt();
				items[total_items]=new department(itemName ,itemCode , price , qtylnStock , soldToday);
				total_items++;
				x=menu.menu();
			}
			if(x==2){
				int itemCode =sc.nextInt();
				float price =sc.nextFloat();
				int temp=-1;
				for(int i=0;i<total_items;i++){
					
					if(itemCode==items[i].getItemcode()){
						items[i].setPrice(price);
						temp++;
					}

				}
				if(temp==-1){
					System.out.println("item not found");
				}
				else{
					System.out.println("item price updated");
				}
				x=menu.menu();
			}
			if(x==3){
				int itemCode =sc.nextInt();
				int stock =sc.nextInt();
				
				int temp=-1;
				for(int i=0;i<total_items;i++){
					
					if(itemCode==items[i].getItemcode()){
						items[i].setQtynStock(stock);
						int t=items[i].getSoldToday();
						t++;
						items[i].setSoldToday(t);
						temp++;
					}

				}
				if(temp==-1){
					System.out.println("item not found");
				}
				else{
					System.out.println("item stock updated");
				}
				x=menu.menu();
			}
			if(x==4){
				System.out.println("printing price list");
				for(int i=0;i<total_items;i++){
					System.out.println((items[i].getItemcode())+" "+(items[i].getPrice()));
				}
				x=menu.menu();
			}
			if(x==5){
				int itemCode =sc.nextInt();
				for(int i=0;i<total_items;i++){
					if(itemCode==items[i].getItemcode()){
						if((items[i].getQtynStock())>0){
							int t=items[i].getSoldToday();
							t++;
							items[i].setSoldToday(t);
							t=items[i].getQtynStock();
							t--;
							items[i].setQtynStock(t);
						}
						else{
							System.out.println("stock not available");
						}
						x=menu.menu();
					}
				}
			}
		}



	}
}