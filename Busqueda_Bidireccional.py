class BidirectionalGraph:
    def __init__(self):
        # Definición del grafo con lugares y sus conexiones
        self.graph = {
            "Casa": ["Parque", "Cafetería"],
            "Parque": ["Cine", "Biblioteca"],
            "Cafetería": ["Parque", "Casa"],
            "Biblioteca": ["Parque", "Gimnasio"],
            "Gimnasio": ["Biblioteca", "Cafetería"],
            "Cine": ["Parque" , "Restaurante"],
            "Restaurante": ["Cine"]
        }

    def bidirectional_search(self, start, goal):
        # Estructuras de datos para la búsqueda bidireccional
        start_queue = [start]  # Cola de búsqueda desde la ubicación de inicio
        goal_queue = [goal]  # Cola de búsqueda desde la ubicación de destino
        start_visited = set()  # Conjunto de ubicaciones visitadas desde el inicio
        goal_visited = set()  # Conjunto de ubicaciones visitadas desde el destino

        while start_queue and goal_queue:
            # Búsqueda desde la ubicación de inicio
            current_start = start_queue.pop(0)  # Extraer el primer elemento de la cola
            start_visited.add(current_start)  # Marcar la ubicación como visitada desde el inicio

            for neighbor in self.graph[current_start]:
                if neighbor not in start_visited:
                    start_queue.append(neighbor)  # Agregar vecinos no visitados a la cola

            # Búsqueda desde la ubicación de destino
            current_goal = goal_queue.pop(0)  # Extraer el primer elemento de la cola
            goal_visited.add(current_goal)  # Marcar la ubicación como visitada desde el destino

            for neighbor in self.graph[current_goal]:
                if neighbor not in goal_visited:
                    goal_queue.append(neighbor)  # Agregar vecinos no visitados a la cola

            # Comprobar si se ha encontrado una intersección
            common_location = set(start_visited) & set(goal_visited)
            if common_location:
                return list(common_location)

        return None

if __name__ == "__main__":
    graph = BidirectionalGraph()
    start_location = "Casa"  # Ubicación de inicio
    goal_location = "Cine"  # Ubicación de destino

    common_locations = graph.bidirectional_search(start_location, goal_location)

    if common_locations:
        print("Camino encontrado:")
        print(start_location)
        for location in common_locations:
            print(location)
        print(goal_location)
    else:
        print(f"No se encontró un camino desde {start_location} a {goal_location}.")