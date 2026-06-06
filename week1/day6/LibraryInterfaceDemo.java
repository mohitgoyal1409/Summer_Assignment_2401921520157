interface LibraryUser {
    void registerAccount();
    void requestBook();
}

class KidUser implements LibraryUser {
    int age;
    String bookType;
    public void registerAccount() {
        if(age<12) {
            System.out.println("you have successfully registered under a kids Account");
        }
        else {
            System.out.println("Sorry , Age must be less than 12 to register as kid");
        }
    }
     
    public void requestBook() {
        if(bookType.equals("Kids")) {
            System.out.println("Book Issued successfully, please return the book within 10 days");
        }
        else {
            System.out.println("Oops , you are allowed to take only kids books");
        }
    }
}

class AdultUser implements LibraryUser {
   int age;
   String bookType;
    public void registerAccount() {

    if(age>12) {
        System.out.println("You have successfully registered under an Adult Account");
    }
    else {
        System.out.println("Sorry, Age must be greater than 12 to register as an adult");
    }
    }

     public void requestBook() {
        if(bookType.equals("Fiction")) {
            System.out.println("Book Issued successfully, please return the book within 7 days");
        }
        else {
            System.out.println("Oops, you are allowed to take only adult Fiction books");
        }
    }
}

class LibraryInterfaceDemo {
    public static void main(String[] args) {
        KidUser k1 = new KidUser();
        AdultUser a1 = new AdultUser();

        // TEST CASE 1
        System.out.println("Test Case 1");
        k1.age = 10;
        k1.bookType = "Kids";
        k1.registerAccount();
        k1.requestBook();
    
        a1.age = 18;
        a1.bookType = "Fiction";
        a1.registerAccount();
        a1.requestBook();

        // TEST CASE 2
        System.out.println("Test Case 2");
        k1.age = 5;
        k1.bookType = "Kids";
        k1.registerAccount();
        k1.requestBook();
        a1.age = 23;
        a1.bookType = "Fiction";
        a1.registerAccount();
        a1.requestBook();
    }
}



[Running] cd "c:\java\" && javac LibraryInterfaceDemo.java && java LibraryInterfaceDemo
Test Case 1
you have successfully registered under a kids Account
Book Issued successfully, please return the book within 10 days
You have successfully registered under an Adult Account
Book Issued successfully, please return the book within 7 days
Test Case 2
you have successfully registered under a kids Account
Book Issued successfully, please return the book within 10 days
You have successfully registered under an Adult Account
Book Issued successfully, please return the book within 7 days

[Done] exited with code=0 in 0.541 seconds


