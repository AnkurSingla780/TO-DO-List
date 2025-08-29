import java.util.Scanner;

class Task {
    String task;
    int priority;
    boolean completed;
    Task next;

    Task(String task, int priority) {
        this.task = task;
        this.priority = priority;
        this.completed = false;
        this.next = null;
    }
}

public class ToDoList {
    private static Task head = null;
    private static Scanner sc = new Scanner(System.in);

    // Add a task
    public static void insertTask(String task, int priority) {
        if (task.isEmpty()) {
            System.out.println("\nTask cannot be empty!");
            return;
        }

        Task newTask = new Task(task, priority);

        if (head == null) {
            head = newTask;
        } else {
            Task temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newTask;
        }
        System.out.println("\nTask added successfully.");
    }

    // Display tasks
    public static void displayTasks() {
        if (head == null) {
            System.out.println("\nNO TASKS AVAILABLE !!!");
            return;
        }
        Task temp = head;
        int i = 1;
        while (temp != null) {
            System.out.println(i + ". " + temp.task + " (Priority: " + temp.priority + ") [" +
                    (temp.completed ? "Completed" : "Not Completed") + "]");
            temp = temp.next;
            i++;
        }
    }

    // Delete task
    public static void deleteTask(String task) {
        if (head == null) {
            System.out.println("\nNO TASKS AVAILABLE !!!");
            return;
        }

        if (head.task.equals(task)) {
            head = head.next;
            System.out.println("\nTask deleted successfully.");
            return;
        }

        Task temp = head;
        Task prev = null;

        while (temp != null && !temp.task.equals(task)) {
            prev = temp;
            temp = temp.next;
        }

        if (temp == null) {
            System.out.println("\nTASK NOT FOUND !!!");
            return;
        }

        prev.next = temp.next;
        System.out.println("\nTask deleted successfully.");
    }

    // Mark task as completed
    public static void markCompleted(String task) {
        if (head == null) {
            System.out.println("\nNO TASKS AVAILABLE !!!");
            return;
        }

        Task temp = head;
        while (temp != null) {
            if (temp.task.equals(task)) {
                temp.completed = true;
                System.out.println("\nTask marked as completed.");
                return;
            }
            temp = temp.next;
        }
        System.out.println("\nTASK NOT FOUND !!!");
    }

    public static void main(String[] args) {
        int choice;
        String task;
        int priority;

        while (true) {
            System.out.println("\n<<<<<< TO-DO List >>>>>>");
            System.out.println("1. Add Task");
            System.out.println("2. Display Tasks");
            System.out.println("3. Delete Task");
            System.out.println("4. Mark Task as Completed");
            System.out.println("5. Exit");
            System.out.println("=======================================================");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();
            sc.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter the task: ");
                    task = sc.nextLine();
                    System.out.print("Enter priority: ");
                    priority = sc.nextInt();
                    sc.nextLine(); // consume newline
                    insertTask(task, priority);
                    break;

                case 2:
                    displayTasks();
                    break;

                case 3:
                    System.out.print("Enter the task to delete: ");
                    task = sc.nextLine();
                    deleteTask(task);
                    break;

                case 4:
                    System.out.print("Enter the task to mark as completed: ");
                    task = sc.nextLine();
                    markCompleted(task);
                    break;

                case 5:
                    System.out.println("Exiting the TO-DO LIST !!");
                    System.exit(0);

                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
